from flask import Flask, render_template, request, redirect
from cs50 import SQL

app = Flask(__name__)

# storing the users name and sport inside of a dictionary
# REGISTRANTS = {}

# using a database to store data
db = SQL('sqlite:///froshims.db')


# Creating a list of sports to use in form
SPORTS = [
    "Dodgeball",
    "Flag Football",
    "Soccer",
    "Volleyball",
    "Ultimate Frisbee"
]

@app.route("/")
def index():
    # adding sports into index
    return render_template("index.html", sports=SPORTS)

@app.route("/register", methods=["POST"])
def register():
    # only submiting the form if the form is valid
    # checking to make sure that the sport chosen was inside of sports
    # if not request.form.get("name") or request.form.get("sport") not in SPORTS:
    #     return render_template("failure.html")
    # return render_template("success.html")

    name = request.form.get("name")
    if not name:
        return render_template("error.html", message="Name is missing")

    sport = request.form.get("sport")
    if not sport:
        return render_template("error.html", message="Sport is missing")

    if sport not in SPORTS:
        return render_template("error.html", message="Invalid sport")

    # name is the key, sport is the value
    # name = indexing into the dictionary
    # sport = the value
    # REGISTRANTS[name] = sport
    # viewing in console
    #print(REGISTRANTS)

    # inserting name and sport into database
    db.execute("INSERT INTO registrants (name, sport) VALUES(?,?)", name, sport)

    return redirect("/registrants")


# Creating a page to view all registrants
@app.route("/registrants")
def registrants():

    # querying database
    rows = db.execute("SELECT * FROM registrants")

    return render_template("registrants.html", rows=rows)