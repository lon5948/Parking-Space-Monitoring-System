from flask import Flask, render_template, session, request, jsonify, flash, redirect, url_for
#from ..Model.model import model

app = Flask(__name__)

@app.route('/', methods=['GET'])
def hello():
    # input -> img
    # cloud to local folder(data)
    dic = {}
    dic['a'] = [1, 4, 17]
    dic['b'] = [2, 6, 9, 18]
    dic['c'] = [4, 8 ,10, 17, 24]
    a, b, c, total, parkingLot = 3, 4, 5, 12, dic
    return render_template('index.html', sectionA = a, sectionB = b, sectionC = c, total = total, parkingLot = parkingLot)