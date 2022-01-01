from flask import Flask, render_template, request, redirect, session
from flask_session import Session

app = Flask(__name__)

# specific to the sessions library
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

@app.route("/")
def index():
    if not session.get("name"):
        # if user not logged in redirect to login
        return redirect("/login")

    return render_template("index.html")

@app.route("/login", methods=["GET","POST"])
def login():
    if request.method == "POST":
        # Remeber that user logged in
        session["name"] = request.form.get("name")

        # Redirect user to index
        return redirect("/")

    return render_template("login.html")

@app.route("/logout")
def logout():
    session["name"] = None
    return redirect("/")