#!/usr/bin/python3
"""
User Model
"""
import hashlib
import uuid


class User():
    """
    User class:
    - id: public string unique (uuid)
    - password: private string hash in MD5
    """

    def __init__(self):
        """
        Initialize a new user:
        - assigned a unique `id`
        """
       
