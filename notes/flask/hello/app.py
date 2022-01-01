from flask import Flask, render_template, request

# __name__ refers to the name of the current file
# so this is a line of code that says turn this file into a flask appplication
app = Flask(__name__)

# now tell flask what my routes are
@app.route("/", methods=["GET", "POST"])
def index():
    # render template gets index.html and index function returns it
    # request gives access to the http request
    # and with is any paramaters within the url
    # so it can parse the query
    if request.method == "GET":
        return render_template("index.html")
    if request.method == "POST":
        return render_template("greet.html", name=request.form.get("name", "Default Place Holder"))




# The defalt method will be GET
# for get request == request.args.get("name")
# for post request == request.form.get("name")
# @app.route("/greet", methods=["POST"])
# def greet():
#     return render_template("greet.html", name=request.form.get("name", "Default Place Holder"))