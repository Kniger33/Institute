from processor import Processor

def main():
    processors = list()

    while True:
        print("1 - Add processor")
        print("2 - Remove processor")
        print("3 - Print all processors")
        print("4 - Find processors by firm-producer")
        print("0 - Exit")
        command = input("Command: ")

        if command == '1':
            proc = Processor(article=input("Article: "),
                             producer=input("Producer: "),
                             name=input("Name: "),
                             cores=input("Cores count: "),
                             frequency=input("Frequency: "),
                             price=input("Price: ")
                             )
            processors.append(proc)

        elif command == '2':
            article = input("Article to delete: ")
            for proc in processors:
                if proc.data.get('article') == article:
                    processors.remove(proc)
        elif command == '3':
            for v in processors:
                print(v)
        elif command == '4':
            producer = input("Producer: ")
            for proc in processors:
                if proc.data.get('producer') == producer:
                    print(proc)
        elif command == '0':
            return
        else:
            print("Undefined command...Try again")


if __name__ == '__main__':
    main()
