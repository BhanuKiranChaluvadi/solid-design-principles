import random

class Card:
    def __init__(self):
        self.cards = [ (rank, suit) for rank in range(1,14)
            for suit in '♠♡♢♣' ]
        random.shuffle(self.cards)
    def deal(self):
        return self.cards.pop()
    def points(self, card):
        rank, suit = card
        if rank == 1: return (1, 11)
        elif 2 <= rank < 11: return (rank, rank)
        else: return (10, 10)

class Shoe(Card):
    def __init__(self, n):
        super().__init__()
        self.shoe = []
        for _ in range(n): self.shoe.extend(self.cards)
        random.shuffle(self.shoe)
    def shuffle_burn(self, n=100):
        random.shuffle(self.shoe)
        self.shoe = self.shoe[n:]
    def deal(self):
        return self.shoe.pop()


if __name__ == "__main__":
    import doctest
    doctest.testmod(verbose=1)