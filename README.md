```markdown
# Хабр - https://habr.com/ea/ewk6JoCJRoH0gK1CcU1ssg~PeZAMwcw2YpHBlwL381Ca-MgrV706XlU1W1N0a4lS0nanrxOWHKDPZkETv31uBq4

# Treed — Утилита для анализа структуры больших датасетов

## Назначение
**Treed** помогает просматривать структуру директорий с тысячами файлов (например, датасеты с 20k+ текстовыми аннотациями). Вместо громоздкого вывода `tree` она **группирует файлы по маске**, сворачивая последовательные группы в одну строку.

**Пример проблемы:**
```
dataset/
├── images/
│   ├── img_001.png
│   ├── img_002.png
│   └── ... (20k файлов)
└── labels/
    ├── img_001.txt
    ├── img_002.txt
    └── ... (20k файлов — tree зависает!)
```

**С treed:**
```bash
tree | treed "*.[png,txt]"
```
**Вывод:**
```
dataset/
├── images/
│   └── 19987 *.png files
└── labels/
    └── 19987 *.txt files
```

## Установка

1. **Скачайте бинарник:**
   ```bash
   wget https://example.com/treed
   ```

2. **Сделайте исполняемым:**
   ```bash
   chmod +x treed
   ```

3. **Установите в систему:**
   ```bash
   sudo cp treed /usr/local/bin/
   ```

## Использование

```bash
# Базовое использование с tree
tree /path/to/dataset | treed "*.txt"

# Группировка по нескольким расширениям
tree | treed "*.[png,jpg,txt]"

# Только изображения
tree dataset | treed "*.png"

# Игнорировать определённые файлы
tree | treed -i "*.log|README.md"
```

## Опции
| Флаг | Описание | Пример |
|------|----------|--------|
| `-h, --help` | Показать справку | `treed --help` |
| `-i PATTERN` | Игнорировать маску | `treed -i "*.log"` |
| `-n COUNT` | Максимум файлов в группе | `treed -n 1000 "*.txt"` |

## Совместимость
- Linux (x86_64)
- macOS (Intel/Apple Silicon)
- Работает с выводом `tree`, `find`, `ls -R`

## Пример для ML/Computer Vision датасетов
```bash
# YOLO/COCO датасеты
tree labels/ | treed "*.txt"   # 20k+ аннотаций → 1 строка

# Изображения
tree images/ | treed "*.[jpg,png,jpeg]"  # Все фото в 1 строку
```

**Экономия времени:** 20k строк → 5 строк вывода за секунды!

## Лицензия
MIT License.
```# tree_group
