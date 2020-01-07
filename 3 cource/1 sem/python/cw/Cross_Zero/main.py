from minimax_classes import *
from players_classes import *

app = Tk()
global p_v_p_size


def start_window():
    app.title("TTT")
    app.geometry('150x150+700+300')
    app.resizable(width=False, height=False)

    label1 = Label(text="Enter PVP board size:")
    label1.pack(expand=True)

    global message
    message = StringVar()

    global message_entry
    message_entry = Entry(textvariable=message)
    message_entry.place(relx=.5, rely=.1, anchor="c")
    message_entry.pack(expand=True)

    player_vs_player = Button(app, text='Player vs Player', command=p_v_p)
    player_vs_player.pack(expand=True)

    player_vs_computer = Button(app, text='Player vs Computer', command=p_v_c)
    player_vs_computer.pack(expand=True)

    app.mainloop()


def p_v_p():
    global p_v_p_size
    try:
        p_v_p_size = int(message.get())
    except ValueError:
        messagebox.showinfo("Value error", "Not integer value")
        message_entry.delete(0, END)
        pass
    if p_v_p_size < 3:
        messagebox.showinfo("Value error", "Value less than 3. Please, enter a larger value")
        message_entry.delete(0, END)
    else:
        GUI_players(app, p_v_p_size).mainloop()
        message_entry.delete(0, END)


def p_v_c():
    GUI_minimax(app).mainloop()


if __name__ == '__main__':
    start_window()
