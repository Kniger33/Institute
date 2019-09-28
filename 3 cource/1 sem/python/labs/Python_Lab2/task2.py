import math
import re

def TaskTwoMain():
    while True:
        print("Ellipse - e (enter two values for ellipse)")
        print("Triangle - t (enter two values for triangle)")
        print("Rectangle - r ( enter two values for rectangle)")
        print("Quit - q")

        commands = list(filter(
                        lambda command: command.lower() in ['e', 't', 'r', 'q'],
                        [i for i in input().split()]
                    ))

        #
        #

        print("Enter a, b:")
        values = list(filter(
            lambda value: re.match("[0-9.0-9]", value),
            [j for j in input().split()]
        ))

        results = list\
                (
                    map
                    (
                        lambda command:
                        (
                            command.lower() == 'e' and
                            (
                                float(values[0]) * float(values[1]) * math.pi
                            )
                            or command.lower() == 't' and
                            (
                                1/2 * float(values[0]) * float(values[1])
                            )
                            or command.lower() == 'r' and (float(values[0]) * float(values[1]))
                            or command.lower() == 'q' and "exit"
                        ),
                        commands
                    )
                )
        list(map
            (
                lambda command, result: print(f'{command}: {result}'),
                commands,
                results
            )
        )
        list(map(
            lambda result:
            (
                result == "exit" and (exit(0))
            ),
            results
        ))