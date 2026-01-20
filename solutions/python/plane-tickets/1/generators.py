"""Functions to automate Conda airlines ticketing system."""


def generate_seat_letters(number):
    """Generate a series of letters for airline seats.

    :param number: int - total number of seat letters to be generated.
    :return: generator - generator that yields seat letters.

    Seat letters are generated from A to D.
    After D it should start again with A.

    Example: A, B, C, D

    """

    current_number = 0
    while current_number < number:
        if current_number % 4 ==  0:
            yield "A"
        if current_number % 4 == 1:
            yield "B"
        if current_number % 4== 2:
            yield "C"
        if current_number % 4== 3:
            yield "D"
        current_number += 1


def generate_seats(number):
    """Generate a series of identifiers for airline seats.

    :param number: int - total number of seats to be generated.
    :return: generator - generator that yields seat numbers.

    A seat number consists of the row number and the seat letter.

    There is no row 13.
    Each row has 4 seats.

    Seats should be sorted from low to high.

    Example: 3C, 3D, 4A, 4B

    """

    current_number = 0
    while current_number < number:
        if current_number//4 + 1 == 13:
            current_number += 4
            number += 4
        
        if current_number % 4 ==  0:
            yield str(current_number//4 + 1) + "A"
        if current_number % 4 == 1:
             yield str(current_number//4 + 1) + "B"
        if current_number % 4== 2:
            yield str(current_number//4 + 1) + "C"
        if current_number % 4== 3:
            yield str(current_number//4 + 1) + "D"
        current_number += 1    

def assign_seats(passengers):
    """Assign seats to passengers.

    :param passengers: list[str] - a list of strings containing names of passengers.
    :return: dict - with the names of the passengers as keys and seat numbers as values.

    Example output: {"Adele": "1A", "Björk": "1B"}

    """
    
    dictionary = dict()
    seat_number = generate_seats(len(passengers))
    for str in passengers:
        dictionary[str] = next(seat_number)

    return dictionary

def generate_codes(seat_numbers, flight_id):
    """Generate codes for a ticket.

    :param seat_numbers: list[str] - list of seat numbers.
    :param flight_id: str - string containing the flight identifier.
    :return: generator - generator that yields 12 character long ticket codes.

    """

    for seat in seat_numbers:
        ticket_number = seat + flight_id
        ticket_number += ('0' * (12 - len(ticket_number)))
        yield ticket_number
