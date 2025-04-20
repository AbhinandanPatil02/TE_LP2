import nltk
from nltk.chat.util import Chat, reflections

# Define pattern-response pairs for Customer Interaction
pairs = [
    [
        r".*\b(order|purchase)\b.*",
        ["You can place your order on our website easily!", "Ordering is simple! Just visit our online store."]
    ],
    [
        r".*\b(payment|pay)\b.*",
        ["We accept credit cards, debit cards, and UPI payments.", "You can pay using online banking or cards."]
    ],
    [
        r".*\b(delivery|shipping)\b.*",
        ["Delivery usually takes 3-5 business days.", "We ship orders within 24 hours after confirmation."]
    ],
    [
        r".*\b(return|refund)\b.*",
        ["You can request a return within 7 days of delivery.", "Refunds are processed within 5 working days after approval."]
    ],
    [
        r".*\b(help|support)\b.*",
        ["Our customer support is available 24/7! You can call or email us.", "Need help? Just reach out through our Contact Us page."]
    ],
    [
        r".*\b(hi|hello|hey)\b.*",
        ["Hello! Welcome to our customer service. How can I assist you today?", "Hi there! How may I help you?"]
    ],
    [
        r".*\b(thank you|thanks)\b.*",
        ["You're welcome! Happy to help.", "Anytime! Let us know if you have more questions."]
    ],
    [
        r".*\b(exit|quit|bye)\b.*",
        ["Goodbye! Have a great day.", "Thank you for visiting us!"]
    ],
    [
        r".*",
        ["I'm sorry, I didn't understand that. Could you please rephrase?", "Hmm, can you please explain that a bit differently?"]
    ]
]

# Chatbot runner
def customer_service_chatbot():
    print("======================================")
    print(" Welcome to ShopEase Customer Service ")
    print("======================================")
    print("Type 'exit' or 'quit' to end the chat.\n")
    chatbot = Chat(pairs, reflections)
    chatbot.converse()

if __name__ == "__main__":
    customer_service_chatbot()
