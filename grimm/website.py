from flask import Flask, render_template, url_for
app = Flask(__name__)

posts = [
    {
        'author': 'Veisakis Manousos',
        'title': 'Rumpelstiltskin',
        'content': 'This is the story of Rumpelstiltskin',
        'date': 'December 22, 2020'
    },
    {
        'author': 'Veisakis Manousos',
        'title': 'Rapunzel',
        'content': 'This is the story of Rapunzel',
        'date': 'December 22, 2020'
    }
]

@app.route("/")
@app.route("/home")
def home():
    return render_template('home.html', posts=posts)

@app.route("/rumpel")
def rumpel():
    return render_template('rumpel.html', title='Rumpelstiltskin')

@app.route("/rapun")
def rapun():
    return render_template('rapun.html', title='Rapunzel')

if __name__ == '__main__':
    app.run(debug=True)
