import sys

def capital_city_search(source_state: str):
  """
  Find the capital city of a state
  and output the result in stdout

  :param source_state: State of which we search the capital city
  :type source_state: str

  Search by key
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
    state_id = states[source_state]
    capital_city = capital_cities[state_id]
    print(capital_city)
  except KeyError:
    print("Unknown state")


if __name__ == '__main__':
  if len(sys.argv) == 2:
    capital_city_search(sys.argv[1])