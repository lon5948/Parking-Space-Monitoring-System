from flask import Flask, render_template, session, request, jsonify, flash, redirect, url_for

app = Flask(__name__)

@app.route('/')
def hello():
    return render_template('index.html')