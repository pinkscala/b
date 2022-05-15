from nltk.chat.util import Chat, reflections

pairs = [
    
    [
        r"hi|hey|hello",
        ["Hello", "Hey there",]
    ], 
    [
        r"my name is (.*)",
        ["Hello %1, How are you today ?",]
    ],
    
]

chat = Chat(pairs,reflections=reflections)

ip = "$TART"

while (ip != "quit"):
    print(chat.respond(ip))
    ip = input()