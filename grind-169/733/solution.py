## python: dfs

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        m = len(image)
        n = len(image[0])
        origColor = image[sr][sc]
        def dfs(r: int, c: int):
            # not inside the image
            if r >= m or c >= n or r < 0 or c < 0:
                return
            # pixel not the same
            if origColor != image[r][c]:
                return
            # already filled with color
            if color == image[r][c]:
                return
            
            image[r][c] = color
            dfs(r + 1, c)
            dfs(r    , c + 1)
            dfs(r - 1, c)
            dfs(r    , c - 1)
        dfs(sr, sc)
        return image

## python: bfs
ass Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        m = len(image)
        n = len(image[0])
        origColor = image[sr][sc]
        def bfs(r, c):
            queue = [[r,c]]
            while queue != []:
                _r, _c = queue.pop(0)
                ## not in the image
                if _r >= m or _c >= n or _r < 0 or _c < 0:
                    continue
                ## not connected
                if image[_r][_c] != origColor:
                    continue
                ## already filled
                if image[_r][_c] == color:
                    continue
                image[_r][_c] = color
                queue.append([_r + 1, _c])
                queue.append([_r - 1, _c])
                queue.append([_r    , _c + 1])
                queue.append([_r    , _c - 1])
        bfs(sr, sc)
        return image
