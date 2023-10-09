00, ,<,run


run,0,<,run
run,1,<,run
run,2,<,run
run,3,<,run
run,4,<,run
run,5,<,run
run,6,<,run
run,7,<,run
run,8,<,run
run, ,>,zeroif
runreverse,0,>,runreverse
runreverse,1,>,runreverse
runreverse,2,>,runreverse
runreverse, ,#,00


read,0, ,zerobegin
read,1, ,onebegin
read,2, ,twobegin
read,3, ,threebegin
read,4, ,fourbegin
read,5, ,fivebegin
read,6, ,sixbegin
read,7, ,sevenbegin
read,8, ,eightbegin
read, ,>,runreverse


zeroif,1,=,read
zeroif,2,=,read
zeroif,3,=,read
zeroif,4,=,read
zeroif,5,=,read
zeroif,6,=,read
zeroif,7,=,read
zeroif,0,>,zeroif
zeroif, ,>,zerowriteif
zerowriteif, ,0,runreverse
zerobegin, ,>,zerorun
zerorun,0,>,zerorun
zerorun,1,>,zerorun
zerorun,2,>,zerorun
zerorun,3,>,zerorun
zerorun,4,>,zerorun
zerorun,5,>,zerorun
zerorun,6,>,zerorun
zerorun,7,>,zerorun
zerorun,8,>,zerorun
zerorun, ,>,zero
zero,0,>,zero
zero,1,>,zero
zero,2,>,zero
zero, ,0,zerowrite
zerowrite,0,>,zerowrite
zerowrite, ,0,zeroreverse
zeroreverse,0,<,zeroreverse
zeroreverse,1,<,zeroreverse
zeroreverse,2,<,zeroreverse
zeroreverse, ,<,zeroback
zeroback,1,<,zeroback
zeroback,2,<,zeroback
zeroback,3,<,zeroback
zeroback,4,<,zeroback
zeroback,5,<,zeroback
zeroback,6,<,zeroback
zeroback,7,<,zeroback
zeroback,8,<,zeroback
zeroback,0,<,zeroback
zeroback, ,0,zeroe
zeroe,0,>,read


onebegin, ,>,onerun
onerun,0,>,onerun
onerun,1,>,onerun
onerun,2,>,onerun
onerun,3,>,onerun
onerun,4,>,onerun
onerun,5,>,onerun
onerun,6,>,onerun
onerun,7,>,onerun
onerun,8,>,onerun
onerun, ,>,oneif
oneif,0,>,one
oneif,1,>,one
oneif,2,>,one
oneif, ,1,onereverse
one,0,>,one
one,1,>,one
one,2,>,one
one, ,0,onewrite
onewrite,0,>,onewrite
onewrite, ,1,onereverse
onereverse,0,<,onereverse
onereverse,1,<,onereverse
onereverse,2,<,onereverse
onereverse, ,<,oneback
oneback,1,<,oneback
oneback,2,<,oneback
oneback,3,<,oneback
oneback,4,<,oneback
oneback,5,<,oneback
oneback,6,<,oneback
oneback,7,<,oneback
oneback,8,<,oneback
oneback,0,<,oneback
oneback, ,1,onee
onee,1,>,read


twobegin, ,>,tworun
tworun,0,>,tworun
tworun,1,>,tworun
tworun,2,>,tworun
tworun,3,>,tworun
tworun,4,>,tworun
tworun,5,>,tworun
tworun,6,>,tworun
tworun,7,>,tworun
tworun,8,>,tworun
tworun, ,>,twoif
twoif,0,>,two
twoif,1,>,two
twoif,2,>,two
twoif, ,2,tworeverse
two,0,>,two
two,1,>,two
two,2,>,two
two, ,0,twowrite
twowrite,0,>,twowrite
twowrite, ,2,tworeverse
tworeverse,0,<,tworeverse
tworeverse,1,<,tworeverse
tworeverse,2,<,tworeverse
tworeverse, ,<,twoback
twoback,1,<,twoback
twoback,2,<,twoback
twoback,3,<,twoback
twoback,4,<,twoback
twoback,5,<,twoback
twoback,6,<,twoback
twoback,7,<,twoback
twoback,8,<,twoback
twoback,0,<,twoback
twoback, ,2,twoe
twoe,2,>,read


threebegin, ,>,threerun
threerun,0,>,threerun
threerun,1,>,threerun
threerun,2,>,threerun
threerun,3,>,threerun
threerun,4,>,threerun
threerun,5,>,threerun
threerun,6,>,threerun
threerun,7,>,threerun
threerun,8,>,threerun
threerun, ,>,three
three,0,>,three
three,1,>,three
three,2,>,three
three, ,1,threewrite
threewrite,1,>,threewrite
threewrite, ,0,threereverse
threereverse,0,<,threereverse
threereverse,1,<,threereverse
threereverse,2,<,threereverse
threereverse, ,<,threeback
threeback,1,<,threeback
threeback,2,<,threeback
threeback,3,<,threeback
threeback,4,<,threeback
threeback,5,<,threeback
threeback,6,<,threeback
threeback,7,<,threeback
threeback,8,<,threeback
threeback,0,<,threeback
threeback, ,3,threee
threee,3,>,read


fourbegin, ,>,fourrun
fourrun,0,>,fourrun
fourrun,1,>,fourrun
fourrun,2,>,fourrun
fourrun,3,>,fourrun
fourrun,4,>,fourrun
fourrun,5,>,fourrun
fourrun,6,>,fourrun
fourrun,7,>,fourrun
fourrun,8,>,fourrun
fourrun, ,>,four
four,0,>,four
four,1,>,four
four,2,>,four
four, ,1,fourwrite
fourwrite,1,>,fourwrite
fourwrite, ,1,fourreverse
fourreverse,0,<,fourreverse
fourreverse,1,<,fourreverse
fourreverse,2,<,fourreverse
fourreverse, ,<,fourback
fourback,1,<,fourback
fourback,2,<,fourback
fourback,3,<,fourback
fourback,4,<,fourback
fourback,5,<,fourback
fourback,6,<,fourback
fourback,7,<,fourback
fourback,8,<,fourback
fourback,0,<,fourback
fourback, ,4,foure
foure,4,>,read


fivebegin, ,>,fiverun
fiverun,0,>,fiverun
fiverun,1,>,fiverun
fiverun,2,>,fiverun
fiverun,3,>,fiverun
fiverun,4,>,fiverun
fiverun,5,>,fiverun
fiverun,6,>,fiverun
fiverun,7,>,fiverun
fiverun,8,>,fiverun
fiverun, ,>,five
five,0,>,five
five,1,>,five
five,2,>,five
five, ,1,fivewrite
fivewrite,1,>,fivewrite
fivewrite, ,2,fivereverse
fivereverse,0,<,fivereverse
fivereverse,1,<,fivereverse
fivereverse,2,<,fivereverse
fivereverse, ,<,fiveback
fiveback,1,<,fiveback
fiveback,2,<,fiveback
fiveback,3,<,fiveback
fiveback,4,<,fiveback
fiveback,5,<,fiveback
fiveback,6,<,fiveback
fiveback,7,<,fiveback
fiveback,8,<,fiveback
fiveback,0,<,fiveback
fiveback, ,5,fivee
fivee,5,>,read


sixbegin, ,>,sixrun
sixrun,0,>,sixrun
sixrun,1,>,sixrun
sixrun,2,>,sixrun
sixrun,3,>,sixrun
sixrun,4,>,sixrun
sixrun,5,>,sixrun
sixrun,6,>,sixrun
sixrun,7,>,sixrun
sixrun,8,>,sixrun
sixrun, ,>,six
six,0,>,six
six,1,>,six
six,2,>,six
six, ,2,sixwrite
sixwrite,2,>,sixwrite
sixwrite, ,0,sixreverse
sixreverse,0,<,sixreverse
sixreverse,1,<,sixreverse
sixreverse,2,<,sixreverse
sixreverse, ,<,sixback
sixback,1,<,sixback
sixback,2,<,sixback
sixback,3,<,sixback
sixback,4,<,sixback
sixback,5,<,sixback
sixback,6,<,sixback
sixback,7,<,sixback
sixback,8,<,sixback
sixback,0,<,sixback
sixback, ,6,sixe
sixe,6,>,read


sevenbegin, ,>,sevenrun
sevenrun,0,>,sevenrun
sevenrun,1,>,sevenrun
sevenrun,2,>,sevenrun
sevenrun,3,>,sevenrun
sevenrun,4,>,sevenrun
sevenrun,5,>,sevenrun
sevenrun,6,>,sevenrun
sevenrun,7,>,sevenrun
sevenrun,8,>,sevenrun
sevenrun, ,>,seven
seven,0,>,seven
seven,1,>,seven
seven,2,>,seven
seven, ,2,sevenwrite
sevenwrite,2,>,sevenwrite
sevenwrite, ,1,sevenreverse
sevenreverse,0,<,sevenreverse
sevenreverse,1,<,sevenreverse
sevenreverse,2,<,sevenreverse
sevenreverse, ,<,sevenback
sevenback,1,<,sevenback
sevenback,2,<,sevenback
sevenback,3,<,sevenback
sevenback,4,<,sevenback
sevenback,5,<,sevenback
sevenback,6,<,sevenback
sevenback,7,<,sevenback
sevenback,8,<,sevenback
sevenback,0,<,sevenback
sevenback, ,7,sevene
sevene,7,>,read


eightbegin, ,>,eightrun
eightrun,0,>,eightrun
eightrun,1,>,eightrun
eightrun,2,>,eightrun
eightrun,3,>,eightrun
eightrun,4,>,eightrun
eightrun,5,>,eightrun
eightrun,6,>,eightrun
eightrun,7,>,eightrun
eightrun,8,>,eightrun
eightrun, ,>,eight
eight,0,>,eight
eight,1,>,eight
eight,2,>,eight
eight, ,2,eightwrite
eightwrite,2,>,eightwrite
eightwrite, ,2,eightreverse
eightreverse,0,<,eightreverse
eightreverse,1,<,eightreverse
eightreverse,2,<,eightreverse
eightreverse, ,<,eightback
eightback,1,<,eightback
eightback,2,<,eightback
eightback,3,<,eightback
eightback,4,<,eightback
eightback,5,<,eightback
eightback,6,<,eightback
eightback,7,<,eightback
eightback,8,<,eightback
eightback,0,<,eightback
eightback, ,8,eighte
eighte,8,>,read
