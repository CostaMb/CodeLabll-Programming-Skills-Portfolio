
# Alexa Tell Me a Joke

## About My Project

I created this project using JavaScript and Node.js. The idea was to make a simple application that can tell jokes to the user.

The application contains a list of jokes. When the user types `joke`, the program chooses a random joke and displays the question and answer in the terminal.

## What the Application Can Do

- Show a welcome message.
- Tell a random joke.
- Display the available commands.
- Avoid repeating the same joke twice in a row.
- Close the application when the user types `exit`.

## Technologies I Used

- JavaScript
- Node.js
- npm
- Visual Studio Code

## Project Files

- `index.js` contains the main code of the application.
- `jokes.js` stores the jokes.
- `validate.js` checks if the jokes have a question and an answer.
- `package.json` contains the project settings and commands.
- `package-lock.json` stores information about the installed packages.

## How to Run the Project

First, Node.js must be installed on the computer.

Open the project folder in Terminal and install the dependencies:

    npm install

To start the application, run:

    npm start

The following commands can be used inside the application:

- `joke` to display a random joke.
- `help` to see the available commands.
- `exit` to close the application.

## How to Test the Project

To check the joke collection, run:

    npm test

The program checks that the jokes contain both a question and an answer.

## What I Learned

While working on this project, I practised using JavaScript functions, arrays, modules, random numbers and user input. I also learned how to use Node.js and npm to run and manage a project.

## Conclusion

This project helped me practise JavaScript and build a small interactive application. I can add more jokes to the collection by editing the `jokes.js` file.
