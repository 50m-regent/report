#!/usr/bin/python3


from bme280_sample import readData

print("Content-Type: text/html\n")


print('<html><meta charset="utf-8"><body>')




print('<h1>Temperature, pressure and humidity information</h1>')
readData()
print('</body></html>')
