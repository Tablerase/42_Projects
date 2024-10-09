import sys

def state_search(capital_city: str):
  """
  Find the state of acapital city
  and output the result in stdout

  :param capital_city: capital city of which we search the State
  :type capital_city: str
  
  Search by value
  """

  states = {
    "Oregon" : "OR",
    "Alabama" : "AL",
    "New Jersey": "NJ",
    "Colorado" : "CO"
  }
  capital_cities = {
    "OR": "Salem",
    "AL": "Montgomery",
    "NJ": "Trenton",
    "CO": "Denver"
  }

  try:
    # next: search for first iteration of value in dict
    state_id = next(key for key, value in capital_cities.items() if value == capital_city)
    state = next(key for key, value in states.items() if value == state_id)
    print(state)
  except StopIteration:
    print("Unknown capital city")

if __name__ == '__main__':
  if len(sys.argv) == 2:
    state_search(sys.argv[1])