import sys
import csv


def main():
    # Propmt user if args dont exist
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # load data.csv into memory
    header = []
    datalist = []
    firstrow = True
    data = sys.argv[1]
    with open(data) as file:
        reader = csv.DictReader(file)

        for row in reader:
            # Setting header
            if firstrow == True:
                for key in row.keys():
                    header.append(key)

                datalist.append(row)
                header.remove('name')
                firstrow = False
            else:
                datalist.append(row)

    # load sequence.txt
    seqlist = []
    seq = sys.argv[2]
    with open(seq, 'r') as f:
        seqlist = f.read()

    # cheking for sequence matches
    seqmatch = []
    for i in range(len(header)):
        seqmatch += checkseq(header[i], seqlist)

    # comparing database and sequence matches
    name = "No match"
    for i in range(len(datalist)):
        person = []

        # setting current person into list
        for value in datalist[i].values():
            person.append(value)

        # removing name and string to ints
        person.remove(person[0])
        for j in range(len(person)):
            person[j] = int(person[j])

        # compairing current person
        if person == seqmatch:
            name = datalist[i]["name"]
            break

    # print name or no match
    print(name)


# return highest squence
def checkseq(STR, seqlist):

    highestseq = 0

    for i in range(len(seqlist)):
        # sequence count
        seqcount = 0

        if seqlist[i: i + len(STR)] == STR:
            seqcount += 1
            while seqlist[i: i + len(STR)] == seqlist[i + len(STR): i + (2 * len(STR))]:
                # add another sequence
                seqcount += 1
                # shift reading by key length
                i += len(STR)

        if highestseq < seqcount:
            highestseq = seqcount

    return [highestseq]


if __name__ == "__main__":
    main()