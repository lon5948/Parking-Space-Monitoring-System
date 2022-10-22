from flask import Flask, render_template
from model import model

app = Flask(__name__)

@app.route('/', methods=['GET'])
def hello():
    # input -> img
    # cloud to local folder(data)
    '''
    dic = {}
    dic['a'] = [1, 4, 17]
    dic['b'] = [2, 6, 9, 18]
    dic['c'] = [4, 8 ,10, 17, 24]
    '''
    filename = "video.gif"
    a, b, c, total, parkingLot = model(filename)
    return render_template('index.html', sectionA = a, sectionB = b, sectionC = c, total = total, parkingLot = parkingLot)  

if __name__ == 'main':
    app.run(debug=True)