from flask import Flask
app = Flask(__name__)

from flask import jsonify

data = {
    "on": True
}

@app.route('/summary')
def summary():
    return jsonify(data)

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=81, debug=True)