import random
from tkinter import *
root = Tk()
root.title('Password Generator')
root.geometry('250x60')
charset = """ !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~"""
    
def generatePassword(pwlen):
    x = ''
    for i in range(0,pwlen):
        x += str(charset[random.randint(0,(len(charset)-1))])
    if(x[0]!=' ' or x[(len(x)-1)]!=' '):
        return(x)
    else:
        generatePassword(pwlen)

def checkint(event):
    a = password_in.get()
    try:
        int(a)
        a = int(a)
        if(a>64):
            password_out.delete(0, "end")
            password_out.config(fg='grey')
            password_out.insert(0, 'Password too long')
        elif(a<8):
            password_out.delete(0, "end")
            password_out.config(fg='grey')
            password_out.insert(0, 'Password too short')
        else:
            password_out.delete(0, "end")
            password_out.config(fg='black')
            password_out.insert(0, generatePassword(a))
    except ValueError:
        password_out.delete(0, "end")
        password_out.config(fg='grey')
        password_out.insert(0, 'Please enter a number')

def on_entry_click(event):
    if password_in.get() == 'Password Length':
        password_in.delete(0, "end")
        password_in.insert(0, '')
        password_in.config(fg='black')
def on_focusout(event):
    if password_in.get() == '':
        password_in.insert(0, 'Password Length')
        password_in.config(fg='grey')
    else:
        checkint(1)
root.bind('<Return>', checkint)

password_in = Entry(root,width = 30,fg='grey')
password_in.place(x = 0,y = 0)
password_in.bind('<FocusIn>', on_entry_click)
password_in.bind('<FocusOut>', on_focusout)
password_in.insert(0, 'Password Length')

password_out = Entry(root,width = 30,fg='black')
password_out.place(x = 0,y = 30)

root.mainloop()
