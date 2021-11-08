import requests
from datetime import date, timedelta
from openpyxl import load_workbook

yesterday = date.today() - timedelta(days=1)
today = date.today()
url = "https://transparency.entsog.eu/api/v1/operationalData.xlsx?from=" + str(yesterday) + "&indicator=Physical%20Flow&limit=-1&periodType=hour&periodize=0&pointDirection=sk-tso-0001itp-00117entry&timezone=CET"
response = requests.get(url=url)
with open(str(today)+ ".xlsx", "wb") as f:
    f.write(response.content)
wb2 = load_workbook(str(today)+ ".xlsx")
wb2.create_sheet(str(today))
wb2.save(str(today)+ ".xlsx")
