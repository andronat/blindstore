import base64
import json

from flask import Flask, request
import numpy as np
from scarab import EncryptedArray, PublicKey
import time

from .store import Store
from common.utils import binary


app = Flask(__name__)

store = Store(database=np.array([[1, 1, 1, 1],
                                 [1, 1, 1, 0],
                                 [1, 1, 0, 0],
                                 [1, 0, 0, 0]]))


@app.route('/db_size')
def get_db_size():
    data = {
        'num_records': store.record_count,
        'record_size': store.record_blength,
        'index_length': store.index_length
    }
    return json.dumps(data), 200, {'Content-Type': 'text/json'}


@app.route('/retrieve', methods=['POST'])
def retrieve():
    start = time.clock()
    public_key = PublicKey(str(request.form['PUBLIC_KEY']))
    enc_index = EncryptedArray(store.index_length, public_key, request.form['ENC_INDEX'])
    try:
        enc_data = store.retrieve2(enc_index, public_key)
    except ValueError as e:
        print(str(e))
        return str(e), 400

    s_bits = [str(b) for b in enc_data]
    obj = json.dumps(s_bits)
    print('Retrieve() took', time.clock() - start, 'seconds')
    return obj


@app.route('/set', methods=['POST'])
def set():
    index = int(request.form['INDEX'])
    data = int.from_bytes(base64.b64decode(request.form['DATA']), 'big')

    store.set(index, binary(data, store.record_blength))
    return '', 200

