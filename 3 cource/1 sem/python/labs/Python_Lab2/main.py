import task1
import task2

while True:
    print("Choose task:")
    print("1 - 1")
    print("2 - 2")
    print("0 - exit")

    task_number = input("Your choose: ")
    print()

    if task_number == '1':
        task1.TaskOneMain()
    elif task_number == '2':
        task2.TaskTwoMain()
    elif task_number == '0':
        break
    else:
        print(task_number + "_Undefined command")