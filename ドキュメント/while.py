#! /user/bin/env /usr/bin/python
# -*- coding: utf-8 -*-

import time

count = 0
while True:
    count = count + 1
    print("カウント" + str(count))
    
    time.sleep(1)