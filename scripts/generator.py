import sys
import random

def generate_position(bounds):
    x = random.randint(0, bounds[0])
    y = random.randint(0, bounds[1])
    return x, y

def generate_radius():
    return random.randint(5, 30)

def generate_speed():
    return random.randint(1, 5)

def generate_delay():
    return random.randint(0, 5)

def generate_tower(bounds):
    x, y = generate_position(bounds)
    radius = generate_radius()
    return f"T {x} {y} {radius}"

def generate_aircraft(bounds):
    departure_x, departure_y = generate_position(bounds)
    arrival_x, arrival_y = generate_position(bounds)
    while departure_x == arrival_x and departure_y == arrival_y:
        arrival_x, arrival_y = generate_position(bounds)
    speed = generate_speed()
    delay = generate_delay()
    return f"A {departure_x} {departure_y} {arrival_x} {arrival_y} {speed} {delay}"

def generate_output(num_towers, num_aircraft):
    bounds = (1920, 1080)
    output = []
    for _ in range(num_towers):
        output.append(generate_tower(bounds))

    for _ in range(num_aircraft):
        output.append(generate_aircraft(bounds))

    return "\n".join(output)

def save_to_file(num_towers, num_aircraft, content):
    filename = f"{num_aircraft}_planes_{num_towers}_towers.rdr"
    with open(filename, 'w') as file:
        file.write(content)
    print(f"Generated output has been saved to {filename}.")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python generate_planes_towers.py <num_towers> <num_aircraft>")
        sys.exit(1)

    num_towers = int(sys.argv[1])
    num_aircraft = int(sys.argv[2])

    generated_output = generate_output(num_towers, num_aircraft)
    save_to_file(num_towers, num_aircraft, generated_output)
