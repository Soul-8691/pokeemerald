    else if (pack == PACK_YUGI_KAIBA)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceYugiKaiba)
				{
					j += 1000 - gCardInfo[i].priceYugiKaiba;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceYugiKaiba;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_CRITTER)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceCritter)
				{
					j += 1000 - gCardInfo[i].priceCritter;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceCritter;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_TREASURE)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceTreasure)
				{
					j += 1000 - gCardInfo[i].priceTreasure;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceTreasure;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_IMPERIAL)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceImperial)
				{
					j += 1000 - gCardInfo[i].priceImperial;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceImperial;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_ANDROID)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceAndroid)
				{
					j += 1000 - gCardInfo[i].priceAndroid;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceAndroid;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_JOEY_PEGASUS)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceJoeyPegasus)
				{
					j += 1000 - gCardInfo[i].priceJoeyPegasus;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceJoeyPegasus;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_FIBER)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceFiber)
				{
					j += 1000 - gCardInfo[i].priceFiber;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceFiber;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_YATA)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceYata)
				{
					j += 1000 - gCardInfo[i].priceYata;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceYata;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_SCIENTIST)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceScientist)
				{
					j += 1000 - gCardInfo[i].priceScientist;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceScientist;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_VAMPIRE)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceVampire)
				{
					j += 1000 - gCardInfo[i].priceVampire;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceVampire;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_CHAOS)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceChaos)
				{
					j += 1000 - gCardInfo[i].priceChaos;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceChaos;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_WARRIOR)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceWarrior)
				{
					j += 1000 - gCardInfo[i].priceWarrior;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceWarrior;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_GOAT)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceGoat)
				{
					j += 1000 - gCardInfo[i].priceGoat;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceGoat;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_CYBER)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceCyber)
				{
					j += 1000 - gCardInfo[i].priceCyber;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceCyber;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_REAPER)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceReaper)
				{
					j += 1000 - gCardInfo[i].priceReaper;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceReaper;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_CHAOS_RETURN)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceChaosReturn)
				{
					j += 1000 - gCardInfo[i].priceChaosReturn;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceChaosReturn;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_DEMISE)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceDemise)
				{
					j += 1000 - gCardInfo[i].priceDemise;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceDemise;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_TROOPER)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceTrooper)
				{
					j += 1000 - gCardInfo[i].priceTrooper;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceTrooper;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_ZOMBIE)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceZombie)
				{
					j += 1000 - gCardInfo[i].priceZombie;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceZombie;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_PERFECT_CIRCLE)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].pricePerfectCircle)
				{
					j += 1000 - gCardInfo[i].pricePerfectCircle;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].pricePerfectCircle;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_DAD_RETURN)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceDADReturn)
				{
					j += 1000 - gCardInfo[i].priceDADReturn;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceDADReturn;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_GLADIATOR)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceGladiator)
				{
					j += 1000 - gCardInfo[i].priceGladiator;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceGladiator;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_TELEDAD)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceTeleDAD)
				{
					j += 1000 - gCardInfo[i].priceTeleDAD;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceTeleDAD;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_CAT)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceCat)
				{
					j += 1000 - gCardInfo[i].priceCat;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceCat;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_EDISON)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceEdison)
				{
					j += 1000 - gCardInfo[i].priceEdison;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceEdison;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_FROG)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceFrog)
				{
					j += 1000 - gCardInfo[i].priceFrog;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceFrog;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_STARSTRIKE)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceStarstrike)
				{
					j += 1000 - gCardInfo[i].priceStarstrike;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceStarstrike;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_TENGU)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceTengu)
				{
					j += 1000 - gCardInfo[i].priceTengu;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceTengu;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_DINO_RABBIT)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceDinoRabbit)
				{
					j += 1000 - gCardInfo[i].priceDinoRabbit;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceDinoRabbit;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_WIND_UP)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceWindUp)
				{
					j += 1000 - gCardInfo[i].priceWindUp;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceWindUp;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_MIAMI)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceMiami)
				{
					j += 1000 - gCardInfo[i].priceMiami;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceMiami;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_MEADOWLANDS)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceMeadowlands)
				{
					j += 1000 - gCardInfo[i].priceMeadowlands;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceMeadowlands;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_BABY_RULER)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceBabyRuler)
				{
					j += 1000 - gCardInfo[i].priceBabyRuler;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceBabyRuler;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_RAVINE_RULER)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceRavineRuler)
				{
					j += 1000 - gCardInfo[i].priceRavineRuler;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceRavineRuler;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_FIRE_WATER)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceFireWater)
				{
					j += 1000 - gCardInfo[i].priceFireWater;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceFireWater;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_HAT)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceHAT)
				{
					j += 1000 - gCardInfo[i].priceHAT;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceHAT;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
    else if (pack == PACK_VEGAS)
		{
			u16 cards[NUM_CARDS];
			for (i = 0; i < NUM_CARDS; i++)
			{
				if (gCardInfo[i].priceVegas)
				{
					j += 1000 - gCardInfo[i].priceVegas;
					cards[length] = i;
					length += 1;
				}
			}
			for (k = 0; k < 5; k++)
			{
				random = Random() % j;
				l = random;
				for (i = 0; i < length; i++)
				{
					u16 rarity = 1000 - gCardInfo[cards[i]].priceVegas;
					u16 card = cards[i];
					l -= rarity;
					if (l <= rarity)
					{
						if (k == 0)
							gSpecialVar_0x8004 = card + 376;
						else if (k == 1)
							gSpecialVar_0x8005 = card + 376;
						else if (k == 2)
							gSpecialVar_0x8006 = card + 376;
						else if (k == 3)
							gSpecialVar_0x8007 = card + 376;
						else if (k == 4)
							gSpecialVar_0x8008 = card + 376;
						break;
					}
				}
			}
		}
