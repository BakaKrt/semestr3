import flet as ft
from Machine import Machine

click_first = False


def main(page: ft.Page):

    machine = Machine()
    
    #
    
    def GLOBAL_INFO_MACHINE():
        machine.set_word(lenta_from_user.value)
        machine.set_instructions(left_row_instructions_field.value)
        a = machine.start_machine()
        if a is None:
            a = [1, 3,"λλλλλλλλ"]
        print(f"Это состояние машины: {a}")
        return a
    
    #
    
    right_column_lenta = ft.Text(
        value="Тут будет какое-то значение после запуска машины",
        size=20,
        bgcolor=ft.colors.TRANSPARENT,
        text_align=ft.TextAlign.CENTER,
    )
    
    right_column_lenta_field = ft.Container(
        content=right_column_lenta,
        width=600,
        height=50,
        border_radius=10,
        padding=10,
        bgcolor="#0f68ad"
    )

    def start_():
        #machine.set_word(lenta_from_user.value)
        #machine.set_instructions(left_row_instructions_field.value)
        #try:
        #    cur_state = machine.start_machine()[-1]
        #except:
        #    cur_state = ""
        cur_state = GLOBAL_INFO_MACHINE()[-1][-1]
        print(cur_state)
        right_column_lenta.value = cur_state
        step_field.clean()
        page.update()
    
    button_start = ft.Container(content=
        ft.Container(content=
            ft.Container(content=
                    ft.Text("СТАРТ", size=40),
                    bgcolor="#0f68ad",
                    on_click = lambda e: (
                        start_(),
                        step_by_step()
                        ),
                    border_radius=7,
                    width=140,
                    height=70,
                    alignment=ft.alignment.center
                ),
            alignment=ft.alignment.bottom_center
        ),
        width=800,
        height=93,
        border_radius=10,
        bgcolor=ft.colors.TRANSPARENT,
        alignment=ft.alignment.bottom_center,
        margin=0
    )
    
#    step_field = ft.TextField(
 #       value="",
  #      color= ft.colors.GREEN,
   ##    height=40,
     #   multiline=True,
      #  disabled=True
    #)
    
    step_field = ft.ListView(
        expand = 1,
    )
  
    def step_by_step():
        left_row_step_by_step.width = 600
        left_row_step_by_step.height = 350
        left_row_step_by_step.bgcolor = ft.colors.BLUE
        step_field.width = 500
        step_field.height = 300
        step_field.bgcolor = ft.colors.WHITE
        a = GLOBAL_INFO_MACHINE()
        for c in a:
            step_field.controls.append(ft.Row(controls=[
                ft.Text(
                    value=c[-1][0:c[1]-1],
                    size=20,
                    height=30,
                ),
                ft.Text(
                    value=c[-1][c[1]-1:c[1]],
                    size=20,
                    height=30,
                    color=ft.colors.RED
                ),
                ft.Text(
                    value=c[-1][c[1]:],
                    size=20,
                    height=30
                ),
            ],spacing=0))
        page.update()
  
    left_row_step_by_step = ft.Container(content=step_field,
        width=0,
        height=0,
        bgcolor=ft.colors.TRANSPARENT
    )
    
    right_container = ft.Container(content=
        ft.Column(controls=[
            ft.Container(content=
                ft.Column(controls=[
                    right_column_lenta_field,
                    left_row_step_by_step
                ]),
                width=800,
                height=650,
                margin=0,
                bgcolor=ft.colors.RED
            ),
            ft.Container(content=
                ft.Column(controls=[
                    button_start
                ])
            )
        ]
    ),
    width=800,
    height=800,
    bgcolor="#8ecbfb",
    padding=10,
    border_radius=10)
    
    def primer1():
        left_row_instructions_field.value = "q1aq1bR\nq1bq1aR\nq1λq2λL\nq2aq0cE"
        lenta_from_user.value = "aaaaaabbbbb"
        page.update()
        
    
    left_row_lr = ft.Column(controls=[
        ft.Container(content=
            ft.Column(controls=[
                ft.Container(content=
                    ft.Text(
                        value="Подсказки:",
                        text_align=ft.alignment.top_right
                    ),
                    alignment=ft.alignment.center
                ),
                ft.Text(
                    value="Пример правильного набора инструкций:\nq1aq2bR\nq2aq3cL\nq3cq0aE"
                )
            ]),
            bgcolor="#b54b64",
            width=350,
            height=250,
            padding=10,
            border_radius=11
        ),
        ft.Container(content=
            ft.Column(controls=[
                ft.Container(content=
                    ft.Text(
                        value="Заготовки инструкций и лент",
                    ),
                    alignment=ft.alignment.center,
                    height=30
                ),
                ft.Container(content=
                    ft.Column(controls=[
                        ft.Row(controls=[
                            ft.Container(width=20,bgcolor=ft.colors.TRANSPARENT),
                            ft.Container(content=ft.Container(content=
                                ft.Text("Пример 1",size=25,text_align=ft.TextAlign.CENTER,color="#0f68ad"),
                                alignment=ft.alignment.center
                            ),
                            width=130,
                            height=83,
                            bgcolor=ft.colors.WHITE,
                            border_radius=10,
                            on_click=lambda e: (primer1())
                        ),
                        ft.Container(content=ft.Container(content=
                                ft.Text("Пример 2",size=25,text_align=ft.TextAlign.CENTER,color="#0f68ad"),
                                alignment=ft.alignment.center
                            ),
                            width=130,
                            height=83,
                            bgcolor=ft.colors.WHITE,
                            border_radius=10
                        )]
                        ),
                        ft.Row(controls=[
                            ft.Container(width=20,bgcolor=ft.colors.TRANSPARENT),
                            ft.Container(content=ft.Container(content=
                                    ft.Text("Пример 3",size=25,text_align=ft.TextAlign.CENTER,color="#0f68ad"),
                                    alignment=ft.alignment.center
                                ),
                            width=130,
                            height=83,
                            bgcolor=ft.colors.WHITE,
                            border_radius=10
                            ),
                            ft.Container(content=ft.Container(content=
                                    ft.Text("Пример 4",size=25,text_align=ft.TextAlign.CENTER,color="#0f68ad"),
                                    alignment=ft.alignment.center
                                ),
                            width=130,
                            height=83,
                            bgcolor=ft.colors.WHITE,
                            border_radius=10,
                            )
                        ])
                    ])
                )
            ]
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
    
    #пытался создать filePicker, но он отваливается и не работает
    def insert_instructions_from_file(e: ft.FilePickerResultEvent):
        left_row_instructions_field.value = (
            " ".join(map(lambda f: f.name, e.files)) if e.files else " "
        )
        left_row_instructions_field.update()
    
    ins_inst_from_f_dialog = ft.FilePicker(),
    #page.overlay.append(ins_inst_from_f_dialog)
    #page.update()
    
    left_row_save_del_butts = ft.Container(
        content=ft.Row(controls=[
            ft.IconButton(
                icon=ft.icons.SAVE,
                icon_color="#0f68ad",
                tooltip="Сохранить текущие инструкции в файл",
                #on_click= lambda _: ins_inst_from_f_dialog.pick_files(allow_multiple=False),
                width=47
            ),
            ft.IconButton(
                icon=ft.icons.UPLOAD_FILE_SHARP,
                icon_color="#b54b64",
                tooltip="Загрузить инструкции из файла",
                #on_click= lambda e: print("Вы типо что-то загрузили хз"),
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
    
    def clear_all_containers():
        left_row_instructions_field.value = ""
        lenta_from_user.value = ""
        right_column_lenta.value = "Тут будет какое-то значение после запуска машины"
        left_row_step_by_step.width = 0
        left_row_step_by_step.height = 0
        step_field.value = ""
        page.update()
    
    def put_lambda():
        left_row_instructions_field.value = left_row_instructions_field.value + "λ"
        page.update()
    
    left_row_instructions_field = ft.TextField(
        hint_text="Напиши сюда свои инструкции",
        value="",
        multiline=True,
        min_lines=1,
        color=ft.colors.WHITE,
        border_color=ft.colors.TRANSPARENT,
        width=300,
        bgcolor="#0f68ad",
        border_radius=10,
    )
    
    left_row_rr_down = ft.Container(
        content=ft.Column(controls=[
            ft.Row(controls=[
                left_row_save_del_butts
            ]),
            ft.ElevatedButton(content=
                ft.Text("Очистить",size=11,tooltip="Очищение всех контейнеров"),
            bgcolor="#0f68ad",
            on_click= lambda e: clear_all_containers(),
            ),
            ft.Container(
                content= ft.Text(value="λ"),
                on_click= lambda e: put_lambda(),
                width=50,
                height=50,
                bgcolor="#b54b64",
                border_radius=10,
                alignment=ft.alignment.center
            )
        ]),
        width=200,
        height=300,
        alignment=ft.alignment.bottom_right,
        border_radius=10
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
        prefix_text="λ",
        suffix_text="λ",
        value="",
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
            alignment=ft.MainAxisAlignment.CENTER
        ),
        ft.Row(controls=[
            left_row_instrucitons_container,
            right_container,
            ],
            alignment=ft.MainAxisAlignment.CENTER
        )
    )
    


ft.app(target=main, view=ft.AppView.WEB_BROWSER)