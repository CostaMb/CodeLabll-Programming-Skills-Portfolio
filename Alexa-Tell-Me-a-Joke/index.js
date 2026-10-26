
const readline = require('readline');
const jokes = require('./jokes');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let lastJokeIndex = -1;

function tellJoke() {
  if (jokes.length === 0) {
    console.log('No jokes available.');
    return;
  }

  let randomIndex;

  if (jokes.length === 1) {
    randomIndex = 0;
  } else {
    do {
      randomIndex = Math.floor(Math.random() * jokes.length);
    } while (randomIndex === lastJokeIndex);
  }

  lastJokeIndex = randomIndex;

  const joke = jokes[randomIndex];

  console.log('\nQuestion: ' + joke.question);
  console.log('Answer: ' + joke.answer);
}

function showHelp() {
  console.log('\nAvailable commands:');
  console.log('joke  - Tell a random joke');
  console.log('help  - Show available commands');
  console.log('exit  - Close the application');
}

function startApp() {
  console.log('\n================================');
  console.log('   ALEXA TELL ME A JOKE');
  console.log('================================');
  console.log('Welcome! Ready for some jokes?');

  showHelp();

  rl.setPrompt('\nEnter a command: ');
  rl.prompt();

  rl.on('line', (input) => {
    const command = input.trim().toLowerCase();

    if (command === 'joke') {
      tellJoke();
    } else if (command === 'help') {
      showHelp();
    } else if (command === 'exit') {
      console.log('\nGoodbye! Thanks for using the app.');
      rl.close();
      return;
    } else {
      console.log('\nUnknown command. Type help to see commands.');
    }

    rl.prompt();
  });
}

startApp();
