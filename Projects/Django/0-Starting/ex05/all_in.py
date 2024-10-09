import sys

def state_id(string_to_search : str):
  states = {
    "Oregon" : "OR",
    "Alabama" : "AL",
    "New Jersey": "NJ",
    "Colorado" : "CO"
  }
  titled_string = string_to_search.title();
  if (titled_string in states):
    return states[titled_string];
  else:
    return None

def state_search(capital_city: str):
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
    state_id = next(key for key, value in capital_cities.items() if value == capital_city.title())
    state = next(key for key, value in states.items() if value == state_id)
    return state
  except StopIteration:
    return None

def all_in(string_all_in : list):
  """
  Detect if input string is a state, a capital city or none of them
  and display the result in stdout

  :param string_all_in: String containing as many expressions as we search for, separated by a coma
  :type string_all_in: str
  """

  capital_cities = {
    "OR": "Salem",
    "AL": "Montgomery",
    "NJ": "Trenton",
    "CO": "Denver"
  }

  for word in string_all_in:
    state_id_res = state_id(word)
    # State to Capital city
    if (state_id_res != None):
      capital_city = capital_cities.get(state_id_res)
      state = word.title()
      print(f"{capital_city} is the capital of {state}\r")
    else:
      # Capital city to State
      state = state_search(word)
      if (state != None):
        capital_city = word.title()
        print(f"{capital_city} is the capital of {state}\r")
      else:
        capital_city = None
        print(f"{word} is neither a capital city nor a state\r")

if __name__ == "__main__":
  if (len(sys.argv) == 2):
    all_in_list = [word.strip() for word in sys.argv[1].split(',') if word.strip()]
    all_in(all_in_list)
