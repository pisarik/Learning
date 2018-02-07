import numpy as np


def strongAgainst(a, b):
    stronger.add((units[a], units[b]))

def weakAgainst(a, b):
    strongAgainst(b, a)

def makeStrongerRelation():
    strongAgainst('Marine', 'Marauder')
    strongAgainst('Marine', 'Hydralisk')
    strongAgainst('Marine', 'Immortal')
    weakAgainst  ('Marine', 'Siege Tank')
    weakAgainst  ('Marine', 'Baneling')
    weakAgainst  ('Marine', 'Colossus')

    strongAgainst('Marauder', 'Thor')
    strongAgainst('Marauder', 'Roach')
    strongAgainst('Marauder', 'Stalker')
    weakAgainst  ('Marauder', 'Marine')
    weakAgainst  ('Marauder', 'Zergling')
    weakAgainst  ('Marauder', 'Zealot')

    strongAgainst('Reaper', 'SCV')
    strongAgainst('Reaper', 'Drone')
    strongAgainst('Reaper', 'Probe')
    weakAgainst  ('Reaper', 'Marauder')
    weakAgainst  ('Reaper', 'Roach')
    weakAgainst  ('Reaper', 'Stalker')

    strongAgainst('Ghost', 'Raven')
    strongAgainst('Ghost', 'Infestor')
    strongAgainst('Ghost', 'High Templar')
    weakAgainst  ('Ghost', 'Marauder')
    weakAgainst  ('Ghost', 'Zergling')
    weakAgainst  ('Ghost', 'Stalker')

    strongAgainst('Hellion', 'Zergling')
    strongAgainst('Hellion', 'Zealot')
    weakAgainst  ('Hellion', 'Marauder')
    weakAgainst  ('Hellion', 'Roach')
    weakAgainst  ('Hellion', 'Stalker')

    strongAgainst('Hellbat', 'Zergling')
    strongAgainst('Hellbat', 'Zealot')
    weakAgainst  ('Hellbat', 'Marauder')
    weakAgainst  ('Hellbat', 'Baneling')
    weakAgainst  ('Hellbat', 'Stalker')

    strongAgainst('Siege Tank', 'Marine')
    strongAgainst('Siege Tank', 'Hydralisk')
    strongAgainst('Siege Tank', 'Stalker')
    weakAgainst  ('Siege Tank', 'Banshee')
    weakAgainst  ('Siege Tank', 'Mutalisk')
    weakAgainst  ('Siege Tank', 'Immortal')

    strongAgainst('Thor', 'Marine')
    strongAgainst('Thor', 'Mutalisk')
    strongAgainst('Thor', 'Stalker')
    weakAgainst  ('Thor', 'Marauder')
    weakAgainst  ('Thor', 'Zergling')
    weakAgainst  ('Thor', 'Immortal')

    strongAgainst('Viking', 'Battlecruiser')
    strongAgainst('Viking', 'Corruptor')
    strongAgainst('Viking', 'Void Ray')
    weakAgainst  ('Viking', 'Marine')
    weakAgainst  ('Viking', 'Mutalisk')
    weakAgainst  ('Viking', 'Stalker')

    strongAgainst('Raven', 'Banshee')
    strongAgainst('Raven', 'Roach')
    strongAgainst('Raven', 'Dark Templar')
    weakAgainst  ('Raven', 'Viking')
    weakAgainst  ('Raven', 'Hydralisk')
    weakAgainst  ('Raven', 'Phoenix')

    strongAgainst('Battlecruiser', 'Thor')
    strongAgainst('Battlecruiser', 'Mutalisk')
    strongAgainst('Battlecruiser', 'Marine')
    weakAgainst  ('Battlecruiser', 'Viking')
    weakAgainst  ('Battlecruiser', 'Corruptor')
    weakAgainst  ('Battlecruiser', 'Void Ray')

    strongAgainst('Widow Mine', 'Marauder')
    strongAgainst('Widow Mine', 'Roach')
    strongAgainst('Widow Mine', 'Immortal')
    weakAgainst  ('Widow Mine', 'Raven')
    weakAgainst  ('Widow Mine', 'Overseer')
    weakAgainst  ('Widow Mine', 'Observer')

    strongAgainst('Liberator', 'Viking')
    strongAgainst('Liberator', 'Mutalisk')
    strongAgainst('Liberator', 'Phoenix')
    weakAgainst  ('Liberator', 'Battlecruiser')
    weakAgainst  ('Liberator', 'Corruptor')
    weakAgainst  ('Liberator', 'Carrier')

    strongAgainst('Cyclone', 'Thor')
    strongAgainst('Cyclone', 'Ultralisk')
    strongAgainst('Cyclone', 'Immortal')
    weakAgainst  ('Cyclone', 'Marine')
    weakAgainst  ('Cyclone', 'Zergling')
    weakAgainst  ('Cyclone', 'Zealot')
    
    strongAgainst('Zealot', 'Marauder')
    strongAgainst('Zealot', 'Zergling')
    strongAgainst('Zealot', 'Immortal')
    weakAgainst  ('Zealot', 'Hellion')
    weakAgainst  ('Zealot', 'Roach')
    weakAgainst  ('Zealot', 'Colossus')

    strongAgainst('Stalker', 'Reaper')
    strongAgainst('Stalker', 'Mutalisk')
    strongAgainst('Stalker', 'Void Ray')
    weakAgainst  ('Stalker', 'Marauder')
    weakAgainst  ('Stalker', 'Zergling')
    weakAgainst  ('Stalker', 'Immortal')

    strongAgainst('Sentry', 'Zergling')
    strongAgainst('Sentry', 'Zealot')
    weakAgainst  ('Sentry', 'Reaper')
    weakAgainst  ('Sentry', 'Hydralisk')
    weakAgainst  ('Sentry', 'Stalker')

    strongAgainst('Immortal', 'Siege Tank')
    strongAgainst('Immortal', 'Roach')
    strongAgainst('Immortal', 'Stalker')
    weakAgainst  ('Immortal', 'Marine')
    weakAgainst  ('Immortal', 'Zergling')
    weakAgainst  ('Immortal', 'Zealot')

    strongAgainst('Colossus', 'Marine')
    strongAgainst('Colossus', 'Zergling')
    strongAgainst('Colossus', 'Zealot')
    weakAgainst  ('Colossus', 'Viking')
    weakAgainst  ('Colossus', 'Corruptor')
    weakAgainst  ('Colossus', 'Immortal')

    strongAgainst('Phoenix', 'Banshee')
    strongAgainst('Phoenix', 'Mutalisk')
    strongAgainst('Phoenix', 'Void Ray')
    weakAgainst  ('Phoenix', 'Battlecruiser')
    weakAgainst  ('Phoenix', 'Corruptor')
    weakAgainst  ('Phoenix', 'Carrier')

    strongAgainst('Void Ray', 'Battlecruiser')
    strongAgainst('Void Ray', 'Corruptor')
    strongAgainst('Void Ray', 'Tempest')
    weakAgainst  ('Void Ray', 'Viking')
    weakAgainst  ('Void Ray', 'Mutalisk')
    weakAgainst  ('Void Ray', 'Phoenix')

    strongAgainst('High Templar', 'Marine')
    strongAgainst('High Templar', 'Hydralisk')
    strongAgainst('High Templar', 'Sentry')
    weakAgainst  ('High Templar', 'Ghost')
    weakAgainst  ('High Templar', 'Roach')
    weakAgainst  ('High Templar', 'Colossus')

    strongAgainst('Dark Templar', 'SCV')
    strongAgainst('Dark Templar', 'Drone')
    strongAgainst('Dark Templar', 'Probe')
    weakAgainst  ('Dark Templar', 'Raven')
    weakAgainst  ('Dark Templar', 'Overseer')
    weakAgainst  ('Dark Templar', 'Observer')

    strongAgainst('Archon', 'Mutalisk')
    weakAgainst  ('Archon', 'Thor')
    weakAgainst  ('Archon', 'Ultralisk')
    weakAgainst  ('Archon', 'Immortal')

    strongAgainst('Carrier', 'Thor')
    strongAgainst('Carrier', 'Mutalisk')
    strongAgainst('Carrier', 'Phoenix')
    weakAgainst  ('Carrier', 'Viking')
    weakAgainst  ('Carrier', 'Corruptor')
    weakAgainst  ('Carrier', 'Void Ray')

    weakAgainst  ('Mothership', 'Viking')
    weakAgainst  ('Mothership', 'Corruptor')
    weakAgainst  ('Mothership', 'Void Ray')

    strongAgainst('Oracle', 'SCV')
    strongAgainst('Oracle', 'Drone')
    strongAgainst('Oracle', 'Probe')
    weakAgainst  ('Oracle', 'Viking')
    weakAgainst  ('Oracle', 'Mutalisk')
    weakAgainst  ('Oracle', 'Phoenix')

    strongAgainst('Tempest', 'Swarm Host')
    strongAgainst('Tempest', 'Siege Tank')
    strongAgainst('Tempest', 'Colossus')
    weakAgainst  ('Tempest', 'Viking')
    weakAgainst  ('Tempest', 'Corruptor')
    weakAgainst  ('Tempest', 'Void Ray')

    strongAgainst('Adept', 'Zergling')
    strongAgainst('Adept', 'Zealot')
    strongAgainst('Adept', 'Marine')
    weakAgainst  ('Adept', 'Roach')
    weakAgainst  ('Adept', 'Stalker')
    weakAgainst  ('Adept', 'Marauder')

    strongAgainst('Disruptor', 'Marauder')
    strongAgainst('Disruptor', 'Hydralisk')
    strongAgainst('Disruptor', 'Probe')
    weakAgainst  ('Disruptor', 'Thor')
    weakAgainst  ('Disruptor', 'Ultralisk')
    weakAgainst  ('Disruptor', 'Immortal')

    strongAgainst('Zergling', 'Marauder')
    strongAgainst('Zergling', 'Hydralisk')
    strongAgainst('Zergling', 'Stalker')
    weakAgainst  ('Zergling', 'Hellion')
    weakAgainst  ('Zergling', 'Baneling')
    weakAgainst  ('Zergling', 'Colossus')

    strongAgainst('Queen', 'Hellion')
    strongAgainst('Queen', 'Mutalisk')
    strongAgainst('Queen', 'Void Ray')
    weakAgainst  ('Queen', 'Marine')
    weakAgainst  ('Queen', 'Zergling')
    weakAgainst  ('Queen', 'Zealot')

    strongAgainst('Hydralisk', 'Banshee')
    strongAgainst('Hydralisk', 'Mutalisk')
    strongAgainst('Hydralisk', 'Void Ray')
    weakAgainst  ('Hydralisk', 'Siege Tank')
    weakAgainst  ('Hydralisk', 'Zergling')
    weakAgainst  ('Hydralisk', 'Colossus')

    strongAgainst('Baneling', 'Marine')
    strongAgainst('Baneling', 'Zergling')
    strongAgainst('Baneling', 'Zealot')
    weakAgainst  ('Baneling', 'Marauder')
    weakAgainst  ('Baneling', 'Roach')
    weakAgainst  ('Baneling', 'Stalker')

    strongAgainst('Overseer', 'Banshee')
    strongAgainst('Overseer', 'Roach')
    strongAgainst('Overseer', 'Dark Templar')
    weakAgainst  ('Overseer', 'Viking')
    weakAgainst  ('Overseer', 'Mutalisk')
    weakAgainst  ('Overseer', 'Stalker')

    strongAgainst('Roach', 'Hellion')
    strongAgainst('Roach', 'Zergling')
    strongAgainst('Roach', 'Zealot')
    weakAgainst  ('Roach', 'Marauder')
    weakAgainst  ('Roach', 'Ultralisk')
    weakAgainst  ('Roach', 'Immortal')

    strongAgainst('Infestor', 'Marine')
    strongAgainst('Infestor', 'Mutalisk')
    strongAgainst('Infestor', 'Immortal')
    weakAgainst  ('Infestor', 'Ghost')
    weakAgainst  ('Infestor', 'Ultralisk')
    weakAgainst  ('Infestor', 'High Templar')

    strongAgainst('Mutalisk', 'Viking')
    strongAgainst('Mutalisk', 'Brood Lord')
    strongAgainst('Mutalisk', 'Void Ray')
    weakAgainst  ('Mutalisk', 'Thor')
    weakAgainst  ('Mutalisk', 'Corruptor')
    weakAgainst  ('Mutalisk', 'Phoenix')

    strongAgainst('Corruptor', 'Battlecruiser')
    strongAgainst('Corruptor', 'Mutalisk')
    strongAgainst('Corruptor', 'Phoenix')
    weakAgainst  ('Corruptor', 'Viking')
    weakAgainst  ('Corruptor', 'Hydralisk')
    weakAgainst  ('Corruptor', 'Void Ray')

    strongAgainst('Ultralisk', 'Marauder')
    strongAgainst('Ultralisk', 'Roach')
    strongAgainst('Ultralisk', 'Stalker')
    weakAgainst  ('Ultralisk', 'Banshee')
    weakAgainst  ('Ultralisk', 'Mutalisk')
    weakAgainst  ('Ultralisk', 'Void Ray')

    strongAgainst('Brood Lord', 'Marine')
    strongAgainst('Brood Lord', 'Hydralisk')
    strongAgainst('Brood Lord', 'Stalker')
    weakAgainst  ('Brood Lord', 'Viking')
    weakAgainst  ('Brood Lord', 'Corruptor')
    weakAgainst  ('Brood Lord', 'Void Ray')

    strongAgainst('Swarm Host', 'Marine')
    strongAgainst('Swarm Host', 'Stalker')
    strongAgainst('Swarm Host', 'Roach')
    weakAgainst  ('Swarm Host', 'Baneling')
    weakAgainst  ('Swarm Host', 'Hellion')
    weakAgainst  ('Swarm Host', 'Archon')

    strongAgainst('Viper', 'Siege Tank')
    strongAgainst('Viper', 'Colossus')
    strongAgainst('Viper', 'Hydralisk')
    weakAgainst  ('Viper', 'Viking')
    weakAgainst  ('Viper', 'Mutalisk')
    weakAgainst  ('Viper', 'Phoenix')

    strongAgainst('Ravager', 'Siege Tank')
    strongAgainst('Ravager', 'Lurker')
    strongAgainst('Ravager', 'Sentry')
    weakAgainst  ('Ravager', 'Marauder')
    weakAgainst  ('Ravager', 'Ultralisk')
    weakAgainst  ('Ravager', 'Immortal')

    strongAgainst('Lurker', 'Marine')
    strongAgainst('Lurker', 'Hydralisk')
    strongAgainst('Lurker', 'Zealot')
    weakAgainst  ('Lurker', 'Siege Tank')
    weakAgainst  ('Lurker', 'Ultralisk')
    weakAgainst  ('Lurker', 'Disruptor')


def writeGraph():
    with open('strongerGraph.tgf', 'w') as f:
        for name, i in units.items():
            print('{} {}'.format(i, name), file=f)

        print('#', file=f)

        for edge_from, edge_to in stronger:
            print('{} {}'.format(edge_from, edge_to), file=f)


if __name__ == '__main__':
    names = []
    names += open('terran_units.txt', 'r').read().split('\n')
    names += open('protoss_units.txt', 'r').read().split('\n')
    names += open('zerg_units.txt', 'r').read().split('\n')
    units = {}
    
    for i, name in enumerate(names):
        units[name] = i+1
    
    stronger = set()
    makeStrongerRelation()
    # writeGraph()
    edges = np.array(list(stronger))

    strgVsCnt = []
    weakVsCnt = []
    diffVsCnt = []
    for i, name in enumerate(names):
        strgVsCnt += [(np.sum(edges[:, 0] == i + 1), name)]
        weakVsCnt += [(np.sum(edges[:, 1] == i + 1), name)]
        diffVsCnt += [(strgVsCnt[-1][0] - weakVsCnt[-1][0], name)]

    print(sorted(strgVsCnt, reverse=True))
    print()
    print(sorted(weakVsCnt, reverse=True))
    print()
    print(sorted(diffVsCnt, reverse=True))
