
const jokes = require('./jokes');

function validateJokes() {
  if (!Array.isArray(jokes) || jokes.length === 0) {
    console.log('Error: No jokes found.');
    return;
  }

  let errors = 0;

  jokes.forEach((joke, index) => {
    if (
      !joke.question ||
      !joke.answer ||
      typeof joke.question !== 'string' ||
      typeof joke.answer !== 'string'
    ) {
      console.log(`Invalid joke at position ${index + 1}`);
      errors++;
    }
  });

  if (errors === 0) {
    console.log('Validation successful!');
    console.log(`Total jokes: ${jokes.length}`);
    console.log('Every joke has a question and an answer.');
  } else {
    console.log(`Validation failed: ${errors} invalid jokes.`);
  }
}

validateJokes();
