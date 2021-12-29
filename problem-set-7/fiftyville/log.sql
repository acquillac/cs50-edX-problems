-- Keep a log of any SQL queries you execute as you solve the mystery.

-- You have been told the cs50 duck has been stolen

-- What You Know:
-- Theft took place on July 28
-- Theft took place on Chamberlin Street

-- query crime scene discription reports on the 28th
SELECT description, year, day, month FROM crime_scene_reports WHERE day = 28 AND month = 7;

-- description | year | day | month
-- Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse. Interviews were conducted today with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse. | 2020 | 28 | 7
-- Money laundering took place at 20:30. No known witnesses. | 2020 | 28 | 7
-- Littering took place at 16:36. No known witnesses. | 2020 | 28 | 7

-- Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse.
--  three witnesses, each of their interview transcripts mentions the courthouse

-- query courthouse_security_logs
SELECT * FROM courthouse_security_logs WHERE day = 28 AND month = 7 AND hour < 11;

-- id | year | month | day | hour | minute | activity | license_plate
-- 219 | 2020 | 7 | 28 | 8 | 2 | entrance | 1M92998
-- 220 | 2020 | 7 | 28 | 8 | 2 | entrance | N507616
-- 221 | 2020 | 7 | 28 | 8 | 2 | exit | 1M92998
-- 222 | 2020 | 7 | 28 | 8 | 2 | exit | N507616
-- 223 | 2020 | 7 | 28 | 8 | 7 | entrance | 7Z8B130
-- 224 | 2020 | 7 | 28 | 8 | 7 | exit | 7Z8B130
-- 225 | 2020 | 7 | 28 | 8 | 13 | entrance | 47MEFVA
-- 226 | 2020 | 7 | 28 | 8 | 13 | exit | 47MEFVA
-- 227 | 2020 | 7 | 28 | 8 | 15 | entrance | D965M59
-- 228 | 2020 | 7 | 28 | 8 | 15 | entrance | HW0488P
-- 229 | 2020 | 7 | 28 | 8 | 15 | exit | D965M59
-- 230 | 2020 | 7 | 28 | 8 | 15 | exit | HW0488P
-- 231 | 2020 | 7 | 28 | 8 | 18 | entrance | L93JTIZ
-- 232 | 2020 | 7 | 28 | 8 | 23 | entrance | 94KL13X
-- 233 | 2020 | 7 | 28 | 8 | 25 | entrance | L68E5I0
-- 234 | 2020 | 7 | 28 | 8 | 25 | entrance | HOD8639
-- 235 | 2020 | 7 | 28 | 8 | 25 | exit | HOD8639
-- 236 | 2020 | 7 | 28 | 8 | 34 | exit | L68E5I0
-- 237 | 2020 | 7 | 28 | 8 | 34 | entrance | 1106N58
-- 238 | 2020 | 7 | 28 | 8 | 34 | entrance | W2CT78U
-- 239 | 2020 | 7 | 28 | 8 | 34 | exit | W2CT78U
-- 240 | 2020 | 7 | 28 | 8 | 36 | entrance | 322W7JE
-- 241 | 2020 | 7 | 28 | 8 | 38 | entrance | 3933NUH
-- 242 | 2020 | 7 | 28 | 8 | 38 | exit | 3933NUH
-- 243 | 2020 | 7 | 28 | 8 | 42 | entrance | 0NTHK55
-- 244 | 2020 | 7 | 28 | 8 | 44 | entrance | 1FBL6TH
-- 245 | 2020 | 7 | 28 | 8 | 44 | exit | 1FBL6TH
-- 246 | 2020 | 7 | 28 | 8 | 49 | entrance | P14PE2Q
-- 247 | 2020 | 7 | 28 | 8 | 49 | exit | P14PE2Q
-- 248 | 2020 | 7 | 28 | 8 | 50 | entrance | 4V16VO0
-- 249 | 2020 | 7 | 28 | 8 | 50 | exit | 4V16VO0
-- 250 | 2020 | 7 | 28 | 8 | 57 | entrance | 8LLB02B
-- 251 | 2020 | 7 | 28 | 8 | 57 | exit | 8LLB02B
-- 252 | 2020 | 7 | 28 | 8 | 59 | entrance | O784M2U
-- 253 | 2020 | 7 | 28 | 8 | 59 | exit | O784M2U
-- 254 | 2020 | 7 | 28 | 9 | 14 | entrance | 4328GD8
-- 255 | 2020 | 7 | 28 | 9 | 15 | entrance | 5P2BI95
-- 256 | 2020 | 7 | 28 | 9 | 20 | entrance | 6P58WS2
-- 257 | 2020 | 7 | 28 | 9 | 28 | entrance | G412CB7
-- 258 | 2020 | 7 | 28 | 10 | 8 | entrance | R3G7486
-- 259 | 2020 | 7 | 28 | 10 | 14 | entrance | 13FNH73
-- 260 | 2020 | 7 | 28 | 10 | 16 | exit | 5P2BI95
-- 261 | 2020 | 7 | 28 | 10 | 18 | exit | 94KL13X
-- 262 | 2020 | 7 | 28 | 10 | 18 | exit | 6P58WS2
-- 263 | 2020 | 7 | 28 | 10 | 19 | exit | 4328GD8
-- 264 | 2020 | 7 | 28 | 10 | 20 | exit | G412CB7
-- 265 | 2020 | 7 | 28 | 10 | 21 | exit | L93JTIZ
-- 266 | 2020 | 7 | 28 | 10 | 23 | exit | 322W7JE
-- 267 | 2020 | 7 | 28 | 10 | 23 | exit | 0NTHK55
-- 268 | 2020 | 7 | 28 | 10 | 35 | exit | 1106N58
-- 269 | 2020 | 7 | 28 | 10 | 42 | entrance | NRYN856
-- 270 | 2020 | 7 | 28 | 10 | 44 | entrance | WD5M8I6
-- 271 | 2020 | 7 | 28 | 10 | 55 | entrance | V47T75I

-- query interviews on the 28th
SELECT * FROM interviews WHERE day = 28 AND month = 7;

-- id | name | year | month | day | transcript
-- 158 | Jose | 2020 | 7 | 28 | “Ah,” said he, “I forgot that I had not seen you for some weeks. It is a little souvenir from the King of Bohemia in return for my assistance in the case of the Irene Adler papers.”
-- 159 | Eugene | 2020 | 7 | 28 | “I suppose,” said Holmes, “that when Mr. Windibank came back from France he was very annoyed at your having gone to the ball.”
-- 160 | Barbara | 2020 | 7 | 28 | “You had my note?” he asked with a deep harsh voice and a strongly marked German accent. “I told you that I would call.” He looked from one to the other of us, as if uncertain which to address.
-- 161 | Ruth | 2020 | 7 | 28 | Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away. If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.
-- 162 | Eugene | 2020 | 7 | 28 | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse, I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.
-- 163 | Raymond | 2020 | 7 | 28 | As the thief was leaving the courthouse, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.


-- 161 | Ruth | 2020 | 7 | 28 | Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away.
-- 261 | 2020 | 7 | 28 | 10 | 18 | exit | 94KL13X
-- 262 | 2020 | 7 | 28 | 10 | 18 | exit | 6P58WS2
-- 263 | 2020 | 7 | 28 | 10 | 19 | exit | 4328GD8
-- 264 | 2020 | 7 | 28 | 10 | 20 | exit | G412CB7
-- 265 | 2020 | 7 | 28 | 10 | 21 | exit | L93JTIZ
-- 266 | 2020 | 7 | 28 | 10 | 23 | exit | 322W7JE
-- 267 | 2020 | 7 | 28 | 10 | 23 | exit | 0NTHK55

-- 162 | Eugene | 2020 | 7 | 28 | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse, I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.
-- query atm atm_transactions
SELECT * FROM atm_transactions WHERE day = 28 AND month = 7 AND atm_location = "Fifer Street";
-- id | account_number | year | month | day | atm_location | transaction_type | amount
-- 246 | 28500762 | 2020 | 7 | 28 | Fifer Street | withdraw | 48
-- 264 | 28296815 | 2020 | 7 | 28 | Fifer Street | withdraw | 20
-- 266 | 76054385 | 2020 | 7 | 28 | Fifer Street | withdraw | 60
-- 267 | 49610011 | 2020 | 7 | 28 | Fifer Street | withdraw | 50
-- 269 | 16153065 | 2020 | 7 | 28 | Fifer Street | withdraw | 80
-- 275 | 86363979 | 2020 | 7 | 28 | Fifer Street | deposit | 10
-- 288 | 25506511 | 2020 | 7 | 28 | Fifer Street | withdraw | 20
-- 313 | 81061156 | 2020 | 7 | 28 | Fifer Street | withdraw | 30
-- 336 | 26013199 | 2020 | 7 | 28 | Fifer Street | withdraw | 35



-- 163 | Raymond | 2020 | 7 | 28 | As the thief was leaving the courthouse, they called someone who talked to them for less than a minute.
--                                In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
--                                The thief then asked the person on the other end of the phone to purchase the flight ticket.
-- query phone calls
SELECT * FROM phone_calls WHERE day = 28 AND month = 7 AND duration < 60;
-- id | caller | receiver | year | month | day | duration
-- 221 | (130) 555-0289 | (996) 555-8899 | 2020 | 7 | 28 | 51
-- 224 | (499) 555-9472 | (892) 555-8872 | 2020 | 7 | 28 | 36
-- 233 | (367) 555-5533 | (375) 555-8161 | 2020 | 7 | 28 | 45
-- 251 | (499) 555-9472 | (717) 555-1342 | 2020 | 7 | 28 | 50
-- 254 | (286) 555-6063 | (676) 555-6554 | 2020 | 7 | 28 | 43
-- 255 | (770) 555-1861 | (725) 555-3243 | 2020 | 7 | 28 | 49
-- 261 | (031) 555-6622 | (910) 555-3251 | 2020 | 7 | 28 | 38
-- 279 | (826) 555-1652 | (066) 555-9701 | 2020 | 7 | 28 | 55
-- 281 | (338) 555-6650 | (704) 555-2131 | 2020 | 7 | 28 | 54

-- Search phone call receiver bank
SELECT * FROM people WHERE phone_number = "(996) 555-8899";
-- id | name | phone_number | passport_number | license_plate
-- 567218 | Jack | (996) 555-8899 | 9029462229 | 52R0Y8U

SELECT * FROM people WHERE phone_number = "(892) 555-8872";
-- id | name | phone_number | passport_number | license_plate
-- 251693 | Larry | (892) 555-8872 | 2312901747 | O268ZZ0

SELECT * FROM people WHERE phone_number = "(375) 555-8161";
-- id | name | phone_number | passport_number | license_plate
-- 864400 | Berthold | (375) 555-8161 |  | 4V16VO0

SELECT * FROM people WHERE phone_number = "(717) 555-1342";
-- id | name | phone_number | passport_number | license_plate
-- 626361 | Melissa | (717) 555-1342 | 7834357192 |

SELECT * FROM people WHERE phone_number = "(676) 555-6554";
-- id | name | phone_number | passport_number | license_plate
-- 250277 | James | (676) 555-6554 | 2438825627 | Q13SVG6

SELECT * FROM people WHERE phone_number = "(725) 555-3243";
-- id | name | phone_number | passport_number | license_plate
-- 847116 | Philip | (725) 555-3243 | 3391710505 | GW362R6

SELECT * FROM people WHERE phone_number = "(910) 555-3251";
-- id | name | phone_number | passport_number | license_plate
-- 712712 | Jacqueline | (910) 555-3251 |  | 43V0R5D

SELECT * FROM people WHERE phone_number = "(066) 555-9701";
-- id | name | phone_number | passport_number | license_plate
-- 953679 | Doris | (066) 555-9701 | 7214083635 | M51FA04

SELECT * FROM people WHERE phone_number = "(704) 555-2131";
-- id | name | phone_number | passport_number | license_plate
-- 953679 | Doris | (066) 555-9701 | 7214083635 | M51FA04



-- Search phone caller
SELECT * FROM people WHERE phone_number = "(130) 555-0289";
-- id | name | phone_number | passport_number | license_plate
-- 398010 | Roger | (130) 555-0289 | 1695452385 | G412CB7

SELECT * FROM people WHERE phone_number = "(499) 555-9472";
-- id | name | phone_number | passport_number | license_plate
-- 560886 | Evelyn | (499) 555-9472 | 8294398571 | 0NTHK55

SELECT * FROM people WHERE phone_number = "(367) 555-5533";
-- id | name | phone_number | passport_number | license_plate
-- 686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X

SELECT * FROM people WHERE phone_number = "(286) 555-6063";
-- id | name | phone_number | passport_number | license_plate
-- 449774 | Madison | (286) 555-6063 | 1988161715 | 1106N58

SELECT * FROM people WHERE phone_number = "(770) 555-1861";
-- id | name | phone_number | passport_number | license_plate
-- 514354 | Russell | (770) 555-1861 | 3592750733 | 322W7JE

SELECT * FROM people WHERE phone_number = "(031) 555-6622";
-- id | name | phone_number | passport_number | license_plate
-- 907148 | Kimberly | (031) 555-6622 | 9628244268 | Q12B3Z3

SELECT * FROM people WHERE phone_number = "(826) 555-1652";
-- id | name | phone_number | passport_number | license_plate
-- 395717 | Bobby | (826) 555-1652 | 9878712108 | 30G67EN

SELECT * FROM people WHERE phone_number = "(338) 555-6650";
-- id | name | phone_number | passport_number | license_plate
-- 438727 | Victoria | (338) 555-6650 | 9586786673 | 8X428L0


-- Searching airport
SELECT * FROM airports WHERE city = "Fiftyville";
-- id | abbreviation | full_name | city
-- 8 | CSF | Fiftyville Regional Airport | Fiftyville
SELECT * FROM flights WHERE id = 8;

-- earliest flight
SELECT * FROM flights WHERE origin_airport_id = 8 AND day = 29 ORDER BY hour;
-- id | origin_airport_id | destination_airport_id | year | month | day | hour | minute
-- 36 | 8                 | 4                      | 2020 | 7     | 29  | 8    | 20

-- passengers
SELECT * FROM passengers WHERE flight_id = 36;
-- flight_id | passport_number | seat
-- 36        | 7214083635      | 2A
-- 36        | 1695452385      | 3B -- 398010 | Roger | (130) 555-0289 | 1695452385 | G412CB7
-- 36        | 5773159633      | 4A -- 686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X
-- 36        | 1540955065      | 5C
-- 36        | 8294398571      | 6C -- 560886 | Evelyn | (499) 555-9472 | 8294398571 | 0NTHK55
-- 36        | 1988161715      | 6D -- 449774 | Madison | (286) 555-6063 | 1988161715 | 1106N58
-- 36        | 9878712108      | 7A -- 395717 | Bobby | (826) 555-1652 | 9878712108 | 30G67EN
-- 36        | 8496433585      | 7B

-- security cam
-- 261 | 2020 | 7 | 28 | 10 | 18 | exit | 94KL13X ---> 686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X
-- 262 | 2020 | 7 | 28 | 10 | 18 | exit | 6P58WS2
-- 263 | 2020 | 7 | 28 | 10 | 19 | exit | 4328GD8
-- 264 | 2020 | 7 | 28 | 10 | 20 | exit | G412CB7 ---> 398010 | Roger | (130) 555-0289 | 1695452385 | G412CB7
-- 265 | 2020 | 7 | 28 | 10 | 21 | exit | L93JTIZ
-- 266 | 2020 | 7 | 28 | 10 | 23 | exit | 322W7JE
-- 267 | 2020 | 7 | 28 | 10 | 23 | exit | 0NTHK55 ---> 560886 | Evelyn | (499) 555-9472 | 8294398571 | 0NTHK55

-- atm
-- 246 | 28500762 | 2020 | 7 | 28 | Fifer Street | withdraw | 48
-- 264 | 28296815 | 2020 | 7 | 28 | Fifer Street | withdraw | 20
-- 266 | 76054385 | 2020 | 7 | 28 | Fifer Street | withdraw | 60
-- 267 | 49610011 | 2020 | 7 | 28 | Fifer Street | withdraw | 50 -----> 49610011 | 686048 | 2010, 686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X
-- 269 | 16153065 | 2020 | 7 | 28 | Fifer Street | withdraw | 80
-- 275 | 86363979 | 2020 | 7 | 28 | Fifer Street | deposit  | 10
-- 288 | 25506511 | 2020 | 7 | 28 | Fifer Street | withdraw | 20
-- 313 | 81061156 | 2020 | 7 | 28 | Fifer Street | withdraw | 30
-- 336 | 26013199 | 2020 | 7 | 28 | Fifer Street | withdraw | 35

-- Suspect
-- 398010 | Roger | (130) 555-0289 | 1695452385 | G412CB7
-- 221 | (130) 555-0289 | (996) 555-8899 | 2020 | 7 | 28 | 51
-- Suspect accomplice
SELECT * FROM people WHERE phone_number = "(996) 555-8899";
-- id | name | phone_number | passport_number | license_plate
-- 567218 | Jack | (996) 555-8899 | 9029462229 | 52R0Y8U



-- Suspect
-- 560886 | Evelyn | (499) 555-9472 | 8294398571 | 0NTHK55
-- Suspect accomplices
-- 224 | (499) 555-9472 | (892) 555-8872 | 2020 | 7 | 28 | 36
SELECT * FROM people WHERE phone_number = "(892) 555-8872";
-- id | name | phone_number | passport_number | license_plate
-- 251693 | Larry | (892) 555-8872 | 2312901747 | O268ZZ0

-- 251 | (499) 555-9472 | (717) 555-1342 | 2020 | 7 | 28 | 50
SELECT * FROM people WHERE phone_number = "(717) 555-1342";
-- id | name | phone_number | passport_number | license_plate
-- 626361 | Melissa | (717) 555-1342 | 7834357192 |




-- Suspect
-- 686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X
-- call
-- 233 | (367) 555-5533 | (375) 555-8161 | 2020 | 7 | 28 | 45
-- Suspect accomplice
SELECT * FROM people WHERE phone_number = "(375) 555-8161";
-- id | name | phone_number | passport_number | license_plate
-- 864400 | Berthold | (375) 555-8161 |  | 4V16VO0


-- bank account matches withdrawl, license plate matches camera, and he took the earliest flight out to  id 4 | LHR | Heathrow Airport | London
SELECT * FROM airports WHERE id = 4;

