import random

# Import beverages
from beverages import Cappucino, HotBeverage, Chocolate, Tea, Coffee, ansi_color

class CoffeeMachine():
    def __init__(self) -> None:
        self.energy_point = 10
        self.working = True

    class EmptyCup(HotBeverage):
        def __init__(self)-> None:
            super().__init__("empty cup", 0.90,"An empty cup?! Gimme my money back!")

    class BrokenMachineException(Exception):
        def __init__(self) -> None:
            super().__init__("This coffee machine has to be repaired.")

    def repair(self):
        if self.working == False:
            self.energy_point = 10
            self.working = True

    def serve(self, beverages_to_serve: HotBeverage) -> HotBeverage :
        if self.energy_point <= 0:
            self.working = False
            raise CoffeeMachine.BrokenMachineException 
        self.energy_point -= 1
        if random.randint(0,1) == True:
            return beverages_to_serve
        else:
            return self.EmptyCup()

def make_beverages(machine: CoffeeMachine):
    list_of_drinks = [Coffee(), Chocolate(), Tea(), Cappucino(), HotBeverage()]
    for i in range(0, 11):
        drink_value = list_of_drinks[random.randint(0, len(list_of_drinks) - 1)]
        drink_served = machine.serve(drink_value)
        print(f"=============[{i}]=============")
        print(drink_served)

if __name__ == "__main__":
    el_distributor = CoffeeMachine() 
    try:
        make_beverages(el_distributor)
    except Exception as broken:
        print(ansi_color("YELB") + str(broken) + ansi_color("RESET"))
        el_distributor.repair()
        try:
            make_beverages(el_distributor)
        except Exception as e:
            print(ansi_color("REDB") + str(e) + ansi_color("RESET"))


