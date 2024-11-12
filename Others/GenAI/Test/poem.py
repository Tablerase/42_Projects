import openai

client = openai.OpenAI()

response = client.chat.completions.create(
    model='gpt-4o-mini',
    messages=[
        { 'role': 'system', 'content': 'You are a helpful assistant.'},
        {
            'role': 'user',
            'content': 'Write a poem about GenerativeAI.'
        }
    ],
    stream=True
)

for chunk in response:
    content = chunk.choices[0].delta.content
    if chunk and content:
        print(content, end='')
