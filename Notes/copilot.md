# Copilot

<img src="https://github.com/images/modules/site/copilot/productivity-bg-head.png" title="Copilot" align="right">

Copilot provides contextualized assistance throughout the software development lifecycle, from code completions in the IDE to code explanations in GitHub and more.

Actuelement base sur GPT 4.0

Database: Github

First Release: 2021

Framework:

- Main: JS, Python, Java

Training of AI on Database: so more used language will have more readyness in the model.

Response with context of files and your prompts

Copilot return to u norms and suggestions adapts to your code with your use.

Gain in repetitive task.

The more complexity you need the less useful AI can help.

You need to have coding base in algorithmic.

## Features

- Completion auto on recuring code

- Data for Copilot AI suggestions:
  - your habitude of code
  - the context of the file. Objectif: soon -> The whole project (beta).

## Example

Demo with open source api and insertion of the data on a webpage.

IDE: JetBrains -> extension Copilot

API: themealdb - meal recipe

Commentary to context Copilot and whats expected

```js
// fetch all data and create a div class card for each meal
```

Copilot read api doc/github projects using the api and fill html and js with the need code.

Important to know what you expected.

Now: Give class details to help Copilot. In futur project analysis will do this.

## Copilot Chat

### How to use

📚 [Documentation for Prompts](https://docs.github.com/en/copilot/using-github-copilot/asking-github-copilot-questions-in-your-ide?tool=vscode)

- Open chat
- Write your question (with appropriate context, and tags)
- Copilot will give you a code snippet

## Security

Data: logout on sensitive data

Watch out with your personal data.

3 type data

- Data engagement user: Error, Latency, Your usage of code, What prompt of copilot u use: 24 month
- Prompts: all context data from project : not saved after suggestion is rendered.
- Suggestions : Same

Option:

- Prevent Github to use your code in his training. However will prevent to adjust your code.

## Pro and cons

Pro:

- Learning (not known language)
- Reduce error (suggestion remove common errors)
- Reduce time on project
- Integrate inside IDE
- Largest opensource data set (Github)

Cons:

- Doesnt not structure your code if you give him a wrong suggestion.
- Cost(for large corpo)
- Slow completion (large data, slow connexion)
