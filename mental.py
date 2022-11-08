from tkinter import*

root = Tk()
root.title('Counting Seconds')
root.geometry("500x500")

range1 = Button(root, text='Stop', command=root.destroy)
range1.grid(row=0,column=0,padx=5,pady=10)
range2 = Button(root, text='Stop', command=root.destroy)
range2.grid(row=0,column=1,padx=5,pady=10)
range3 = Button(root, text='Stop', command=root.destroy)
range3.grid(row=0,column=2,padx=5,pady=10)
range4 = Button(root, text='Stop', command=root.destroy)
range4.grid(row=0,column=3,padx=5,pady=10)
range5 = Button(root, text='Stop', command=root.destroy)
range5.grid(row=0,column=4,padx=5,pady=10)



root.mainloop()