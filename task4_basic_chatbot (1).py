"""
==============================================
TASK: Build a simple rule-based chatbot
CONCEPTS USED: if-elif, functions, loops, input/output
==============================================
"""


def get_response(user_input):
    # Convert input to lowercase so matching works
    # regardless of how the user types (Hello, HELLO, hello)
    user_input = user_input.lower().strip()

    if user_input in ["hello", "hi", "hey"]:
        return "Hi! How can I help you today?"

    elif user_input in ["how are you", "how are you?"]:
        return "I'm fine, thanks! How about you?"

    elif user_input in ["what is your name", "what is your name?", "who are you"]:
        return "I'm a simple chatbot built with Python!"

    elif user_input in ["bye", "goodbye", "exit", "quit"]:
        return "Goodbye! Have a great day!"

    elif user_input in ["thank you", "thanks"]:
        return "You're welcome!"

    else:
        return "Sorry, I didn't understand that. Can you rephrase?"


def start_chat():
    print("Chatbot: Hello! Type 'bye' to end the conversation.\n")

    while True:
        user_input = input("You: ")

        response = get_response(user_input)
        print(f"Chatbot: {response}")

        # End the loop when user says a goodbye word
        if user_input.lower().strip() in ["bye", "goodbye", "exit", "quit"]:
            break


if __name__ == "__main__":
    start_chat()
    input("\nPress Enter to exit...")
