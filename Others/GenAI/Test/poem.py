import openai

client = openai.OpenAI()

completion = client.chat.completions.create(
    model='gpt-4o-mini',
    messages=[
        { 'role': 'system', 'content': 'You are a helpful assistant.'},
        {
            'role': 'user',
            'content': 'Write a poem about GenerativeAI.'
        }
    ]
)

print(completion.choices[0].message)
