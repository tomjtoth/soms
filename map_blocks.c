/// box drawing characters take up 3 code points (?)
/// idk how to make this simpler
/// so I'm using strings instead and memcmp for comparison later
const char *map_walls[] ={
    "\U00002500",
    "\U00002501",
    "\U00002502",
    "\U00002503",
    "\U0000250C",
    "\U0000250D",
    "\U0000250E",
    "\U0000250F",
    "\U00002510",
    "\U00002511",
    "\U00002512",
    "\U00002513",
    "\U00002514",
    "\U00002515",
    "\U00002516",
    "\U00002517",
    "\U00002518",
    "\U00002519",
    "\U0000251A",
    "\U0000251B",
    "\U0000251C",
    "\U0000251D",
    "\U0000251E",
    "\U0000251F",
    "\U00002520",
    "\U00002521",
    "\U00002522",
    "\U00002523",
    "\U00002524",
    "\U00002525",
    "\U00002526",
    "\U00002527",
    "\U00002528",
    "\U00002529",
    "\U0000252A",
    "\U0000252B",
    "\U0000252C",
    "\U0000252D",
    "\U0000252E",
    "\U0000252F",
    "\U00002530",
    "\U00002531",
    "\U00002532",
    "\U00002533",
    "\U00002534",
    "\U00002535",
    "\U00002536",
    "\U00002537",
    "\U00002538",
    "\U00002539",
    "\U0000253A",
    "\U0000253B",
    "\U0000253C",
    "\U0000253D",
    "\U0000253E",
    "\U0000253F",
    "\U00002540",
    "\U00002541",
    "\U00002542",
    "\U00002543",
    "\U00002544",
    "\U00002545",
    "\U00002546",
    "\U00002547",
    "\U00002548",
    "\U00002549",
    "\U0000254A",
    "\U0000254B",
    "\U00002550",
    "\U00002551",
    "\U00002552",
    "\U00002553",
    "\U00002554",
    "\U00002555",
    "\U00002556",
    "\U00002557",
    "\U00002558",
    "\U00002559",
    "\U0000255A",
    "\U0000255B",
    "\U0000255C",
    "\U0000255D",
    "\U0000255E",
    "\U0000255F",
    "\U00002560",
    "\U00002561",
    "\U00002562",
    "\U00002563",
    "\U00002564",
    "\U00002565",
    "\U00002566",
    "\U00002567",
    "\U00002568",
    "\U00002569",
    "\U0000256A",
    "\U0000256B",
    "\U0000256C",
    "\U0000256D",
    "\U0000256E",
    "\U0000256F",
    "\U00002570",


    // idk if I'll actually need these, they look weird :D
    "\U00002571",
    "\U00002572",
    "\U00002573",
    "\U00002574",
    "\U00002575",
    "\U00002576",
    "\U00002577",
    "\U00002578",
    "\U00002579",
    "\U0000257A",
    "\U0000257B",
    "\U0000257C",
    "\U0000257D",
    "\U0000257E",
    "\U0000257F"

};

const char *map_windows[] ={
    "\U00002504",
    "\U00002505",
    "\U00002506",
    "\U00002507",
    "\U00002508",
    "\U00002509",
    "\U0000250A",
    "\U0000250B",
};

const char *map_doors[] = {
    "\U0000254C",
    "\U0000254D",
    "\U0000254E",
    "\U0000254F",
};
