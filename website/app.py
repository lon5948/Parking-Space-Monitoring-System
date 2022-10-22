import os
from flask_bcrypt import Bcrypt
from flask import Flask, render_template, session, request, jsonify, flash, redirect, url_for
from flask_paginate import Pagination
from werkzeug.utils import secure_filename
import mysql.connector
import datetime
import time

app = Flask(__name__)

@app.route('/')
def hello():
    return render_template('index.html')