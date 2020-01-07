from tkinter import *
from tkinter import messagebox
from tkinter.font import Font
from copy import deepcopy


class PlayerBoard:
    def __init__(self, size, other=None):
        self.player = 'X'
        self.opponent = 'O'
        self.current_player = self.player
        self.empty = '.'
        self.size = size
        self.fields = {}
        for y in range(self.size):
            for x in range(self.size):
                self.fields[x, y] = self.empty
        # copy constructor
        if other:
            self.__dict__ = deepcopy(other.__dict__)

    def move(self, x, y):
        # board = PlayerBoard(self.size, self)
        self.fields[x, y] = self.current_player
        self.current_player = self.player if self.current_player == 'O' else self.opponent
        return self

    def tied(self):
        for (x, y) in self.fields:
            if self.fields[x, y] == self.empty:
                return False
        return True

    def won(self, player):
        # horizontal
        for y in range(self.size):
            winning = []
            for x in range(self.size):
                if self.fields[x, y] == player:
                    winning.append((x, y))
            if len(winning) == self.size:
                return winning
        # vertical
        for x in range(self.size):
            winning = []
            for y in range(self.size):
                if self.fields[x, y] == player:
                    winning.append((x, y))
            if len(winning) == self.size:
                return winning
        # diagonal
        winning = []
        for y in range(self.size):
            x = y
            if self.fields[x, y] == player:
                winning.append((x, y))
        if len(winning) == self.size:
            return winning
        # other diagonal
        winning = []
        for y in range(self.size):
            x = self.size - 1 - y
            if self.fields[x, y] == player:
                winning.append((x, y))
        if len(winning) == self.size:
            return winning
        # default
        return None

    def __str__(self):
        string = ''
        for y in range(self.size):
            for x in range(self.size):
                string += self.fields[x, y]
            string += "\n"
        return string


class GUI_players:
    def __init__(self, window, size):
        self.children_app = Toplevel(window)
        self.children_app.title('TicTacToe')
        self.children_app.resizable(width=False, height=False)

        self.board_size = size
        self.board = PlayerBoard(size)

        self.font = Font(family="Helvetica", size=32)

        self.buttons = {}
        for x, y in self.board.fields:
            button = Button(self.children_app, command=lambda x_l=x, y_l=y: self.move(x_l, y_l), font=self.font)
            button.grid(row=y, column=x)
            self.buttons[x, y] = button
        button = Button(self.children_app, text='reset', command=self.reset)
        button.grid(row=self.board.size + 1, column=0, columnspan=self.board.size, sticky="WE")

        self.update()

    def reset(self):
        self.board = PlayerBoard(self.board_size)
        self.update()

    def move(self, x, y):
        self.children_app.config(cursor="watch")
        self.children_app.update()
        # self.board = self.board.move(x, y)
        self.board.move(x, y)
        self.update()
        self.children_app.config(cursor="")

    def update(self):
        for (x, y) in self.board.fields:
            text = self.board.fields[x, y]

            self.buttons[x, y]['text'] = text
            self.buttons[x, y]['disabledforeground'] = 'black'

            if text == self.board.empty:
                self.buttons[x, y]['state'] = 'normal'
            else:
                self.buttons[x, y]['state'] = 'disabled'

        winning = self.board.won(self.board.player)
        if winning:
            for x, y in winning:
                self.buttons[x, y]['disabledforeground'] = 'red'
            for x, y in self.buttons:
                self.buttons[x, y]['state'] = 'disabled'
            messagebox.showinfo("Winner", "Player 'X' wins")

        winning = self.board.won(self.board.opponent)
        if winning:
            for x, y in winning:
                self.buttons[x, y]['disabledforeground'] = 'red'
            for x, y in self.buttons:
                self.buttons[x, y]['state'] = 'disabled'
            messagebox.showinfo("Winner", "Player 'O' wins")

        tie = self.board.tied()
        if tie:
            messagebox.showinfo("Tie", "Oops, it`s tie!")

        for (x, y) in self.board.fields:
            self.buttons[x, y].update()

    def mainloop(self):
        self.children_app.mainloop()
