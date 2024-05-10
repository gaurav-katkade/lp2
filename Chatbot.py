from datetime import date, datetime
import webbrowser

disc = {
    "hello": "hi there! how can i help you",
    "what is your name?": "my name is chatbot",
    "what is date today?": str(date.today()),
    "what is time?": str(datetime.now().strftime("%H:%M:%S")),
    "Please open google": ["https://www.google.com"],
}
to_con = ""
while to_con.lower() != "bye":
    to_con = input("YOU : ")
    if to_con.lower() != "bye":
        flag = False
        for k in disc:
            if k.lower() == to_con.lower():
                if isinstance(disc[k], str):  # Corrected type checking
                    print("Bot :" + disc[k]) 
                else:
                    webbrowser.open(disc[k][0])
                flag = True
                break
        if not flag:
            print("sorry ! I am chatbot not human")
print("Bot : Nice talking to you !!")
