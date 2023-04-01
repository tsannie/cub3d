# cub3d

42cursus - (2021-2022) 💻

- Result : 103/100 ✅

This project is my first big project in C for my 42 cursus. In retrospect, this project was a great learning experience for me and I would not have used the same approach if I had to do it again even though I was quite happy at the time (me from the future) 😅.

![screen](https://i.imgur.com/dAN9lek.gif)

## 📝 Description

The goal of this project is to create a 3D game engine using `raycasting`. The game engine is able to render walls, floors and ceilings, and to display sprites. The game engine is also able to move and rotate the player.

For map creation, we can design them directly with the `.cub` file:

- `R` : resolution
- `NO` : north texture
- `SO` : south texture
- `WE` : west texture
- `EA` : east texture
- `S` : sprite texture
- `F` : floor color
- `C` : ceiling color

- `1` : wall
- `0` : empty space
- `2` : sprite
- `N` / `S` / `E` / `W` : player position and orientation

Example of a `.cub` file:

```
R 1270 720
NO ./texture/nord.xpm
SO ./texture/sud.xpm
WE ./texture/gauche.xpm
EA ./texture/droite.xpm
S ./texture/chest.xpm

F 150,0,50
C 88,185,200

1111111111111
10000000000001
1000000000S001
10000000000001
10000000000001
10000000000001
10000000000001
10000000000001
10000000000001
10000000000001
10000022000001
11111111111111
```

## 🚀 Usage

```bash
git clone git@github.com:tsannie/cub3d.git && cd cub3d
make

./cub3D <path_to_config_file.cub>
```

## 👤 Author

[@tsannie](https://github.com/tsannie)
