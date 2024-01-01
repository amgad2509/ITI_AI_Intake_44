import re
import time
from datetime import datetime

def validate_email(email):
    return re.match(r"^([a-zA-Z0-9_\-\.]+)@([a-zA-Z0-9_\-\.]+)\.([a-zA-Z]{2,5})$", email)

def validate_phone(phone):
    return re.match(r"01[0-6]\d{8}", phone)

def validate_date(date_string):
    try:
        datetime.strptime(date_string, '%Y-%m-%d')
        return True
    except ValueError:
        return False