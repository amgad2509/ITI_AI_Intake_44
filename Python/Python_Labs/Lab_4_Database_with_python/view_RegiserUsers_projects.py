def view_projects():
    l=[]
    print("\nAll Projects:")
    with open("projects_data.txt", "r") as file:
        for line in file:
            print(line.strip())
            l.append(line.strip())
        if not l:
            print("\nYou don't have any projects ..")  

def view_registered_users():
    print("\nRegistered Users:")
    with open("users_data.txt", "r") as file:
        for line in file:
            print(line.strip())