from flask import Flask, render_template
from model import model

app = Flask(__name__)

@app.route('/', methods=['GET'])
def hello():
    filename = "img.jpg"
    a, b, c, total, parkingLot = model(filename)
    return render_template('index.html', sectionA = a, sectionB = b, sectionC = c, total = total, parkingLot = parkingLot)  
 