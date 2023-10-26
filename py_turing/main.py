import flet as ft
from Machine import Machine

click_first = False


def main(page: ft.Page):

    machine = Machine()

    instructions = []

    def start(e):
        for i in range(0, len(instructions)):
            state1 = instructions[i].controls[0].value
            state2 = instructions[i].controls[3].value
            letter1 = instructions[i].controls[1].value
            letter2 = instructions[i].controls[2].value
            direction = instructions[i].controls[4].value
            machine.add_instruction(state1, letter1, letter2, direction, state2)

        lent = machine.start_machine()
        right_container.content.controls.append(
            ft.Text(
                value=f"{lent}",
                color=ft.colors.BLACK
            )
        )

        page.update()


    def click_word_button(e):
        global click_first
        if not click_first:
            machine.set_word(word.value)
            right_container.content.controls.append(
                ft.Text(
                    value=machine.lent,
                    color=ft.colors.BLACK
                )
            )
            right_container.content.controls.append(
                ft.ElevatedButton(text="Результаты", on_click=start)
            )
            click_first = True
        else:
            instructions.append(left_container.content.controls[-2])

        if len(instructions) != 0:
            state1 = instructions[-1].controls[0].value
            state2 = instructions[-1].controls[3].value
            letter1 = instructions[-1].controls[1].value
            letter2 = instructions[-1].controls[2].value
            direction = instructions[-1].controls[4].value
            right_container.content.controls.append(
                ft.Text(
                    value=f"{state1}->{state2}  {letter1}->{letter2}  {direction}",
                    color=ft.colors.BLACK
                )
            )

        icon_button = left_container.content.controls.pop()
        
        left_container.content.controls.append(
            ft.Row(
                controls=[
                    ft.TextField(
                        hint_text="Состояние",
                        color=ft.colors.WHITE,
                        width=110,
                        text_size=15
                    ),
                    ft.TextField(
                        hint_text="Буква",
                        color=ft.colors.WHITE,
                        width=110,
                        text_size=15
                    ),
                    ft.TextField(
                        hint_text="Замена буквы",
                        color=ft.colors.WHITE,
                        width=125,
                        text_size=15
                    ),
                    ft.TextField(
                        hint_text="Замена состояния",
                        color=ft.colors.WHITE,
                        width=125,
                        text_size=15
                    ),
                    ft.TextField(
                        hint_text="Направление",
                        color=ft.colors.WHITE,
                        width=125,
                        text_size=15
                    )
                ]            
            )
        )
        left_container.content.controls.append(
            ft.Row(
                controls=[
                    icon_button
                ]
            )
        )
        page.update()

    word = ft.TextField(
        hint_text="Введите слово...",
        color=ft.colors.WHITE,
        width=550
    )

    left_column = ft.Column(
            controls=[
                ft.Text(
                    value="Настройка машины",
                    font_family="Lato",
                    color=ft.colors.WHITE,
                    style=ft.TextThemeStyle.TITLE_LARGE
                ),
                word,
                ft.IconButton(
                    icon=ft.icons.ADD,
                    icon_color=ft.colors.BLACK,
                    bgcolor=ft.colors.WHITE,
                    on_click=click_word_button
                )
            ],
            horizontal_alignment=ft.CrossAxisAlignment.CENTER
    )
    left_container = ft.Container(
        content=left_column,
        bgcolor=ft.colors.GREY_900,
        width=700,
        height=700
    )

    right_column = ft.Column(
        controls=[
            ft.Text(
                value="Показ машины",
                style=ft.TextThemeStyle.TITLE_LARGE,
                font_family="Lato"
            )
        ],
        horizontal_alignment=ft.CrossAxisAlignment.CENTER
    )

    right_container = ft.Container(
        content=right_column,
        bgcolor="#8ecbfb",
        width=800,
        height=800,
        padding=10,
        #margin=10,
        border_radius=10
    )
    
    left_row_lr = ft.Column(controls=[
        ft.Container(
            content=ft.Text(
                value="Подсказки:",
                text_align=ft.alignment.top_right
            ),
            bgcolor="#b54b64",
            width=350,
            height=250,
            padding=10,
            border_radius=11
        ),
        ft.Container(
            content=ft.Text(
                value="А сюда можно ебануть заготовки инструкций и лент",
                text_align=ft.alignment.top_center
            ),
            theme=ft.Theme(color_scheme_seed=ft.colors.INDIGO),
            theme_mode=ft.ThemeMode.DARK,
            bgcolor=ft.colors.SURFACE_VARIANT,
            padding=10,
            width=350,
            height=250,
            border_radius=11
        )
    ])
    
    left_row_save_del_butts = ft.Container(
        content=ft.Row(controls=[
            ft.IconButton(
                icon=ft.icons.SAVE,
                icon_color="#0f68ad",
                on_click= lambda e: print("Вы типо сохранили какую-то хуйню"),
                width=47
            ),
            ft.IconButton(
                icon=ft.icons.UPLOAD_FILE_SHARP,
                icon_color="#b54b64",
                on_click= lambda e: print("Вы типо что-то загрузили хз"),
                width=30
            )
        ],
            alignment=ft.CrossAxisAlignment.STRETCH
        ),
        width=100,
        height=56,
        border_radius=10,
        bgcolor=ft.colors.WHITE,
    )
    
    
    left_row_rr_down = ft.Container(
        content=ft.Column(controls=[
            ft.Row(controls=[
                left_row_save_del_butts
            ]),
            
            ft.ElevatedButton(content=
                ft.Text("Загрузить",size=11),
            bgcolor="#0f68ad",
            on_click= lambda e: machine.set_instructions(left_row_instructions_field.value),
        ),
        ]),
        width=120,
        height=100,
        alignment=ft.alignment.bottom_right,
        border_radius=10
    )
    
    left_row_instructions_field = ft.TextField(
        label="Ебани сюда свои инструкции",
        multiline=True,
        min_lines=1,
        color=ft.colors.WHITE,
        border_color=ft.colors.TRANSPARENT,
        width=300,
        bgcolor="#0f68ad",
        border_radius=10,
    )
    
    left_row_right_column = ft.Row(controls=[
        left_row_lr,
        ft.Container(
            content=ft.Row(controls=[left_row_instructions_field]
            ),
            alignment=ft.alignment.top_center
        ),
        ft.Container(ft.Column(controls=[
            left_row_rr_down
        ])
        )]
    )

    
    
    left_row_instrucitons_container = ft.Container(
        content=left_row_right_column,
        bgcolor="#8ecbfb",
        width=800,
        height=800,
        border_radius=10,
        padding=10
    )
    
    lenta_from_user = ft.TextField(
        hint_text="Введите слово для ленты",
        bgcolor="#b54b64",
        border_color=ft.colors.TRANSPARENT,
        width=1000,
        text_size=40,
        text_align=ft.TextAlign.CENTER,
    )
    
    center_column_down = ft.Row(
        controls=[lenta_from_user],
    )


    
    center_lenta_container = ft.Container(
        content = center_column_down,
        bgcolor="#b54b64",
        width=1000,
        height=120,
        alignment=ft.alignment.center,
        border_radius=10
    )

    page.add(
        ft.Row(controls=[
            center_lenta_container
            ],
            alignment=ft.MainAxisAlignment.CENTER),
        ft.Row(controls=[
            ft.Container(
                width=135,
                height=800,
                bgcolor=ft.colors.TRANSPARENT,
                margin=0
            ),
            left_row_instrucitons_container,
            right_container
        ])
    )
    


ft.app(target=main, view=ft.AppView.WEB_BROWSER)