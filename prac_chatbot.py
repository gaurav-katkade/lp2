from datetime import date,datetime
import webbrowser
disc={
    "hello":"yoo",
    "open google":["www.google.com"],
    "time":str(datetime.now().strftime("%H:%M:%S"))
}
cont = ""
while cont.lower()!="bye":
    cont = input("YOU : ")
    if cont.lower()!="bye":
            for k in disc:
                flag = False
                if cont.lower()==k.lower():
                    flag = True
                    if isinstance(disc[k],str):
                        print("BOT :"+disc[k])
                    else:
                        webbrowser.open(disc[k][0])
            if not flag:
                print("I don't know")