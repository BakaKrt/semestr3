import flet as ft
from Machine import Machine

#click_first = False
main_color_1 = "#1abc9c"
main_color_2 = "#d35400"
main_color_3 = "#34495e"
#main_color_3 = "#6E6C78"


def main(page: ft.Page):
    #page.bgcolor = "#3B3A3D"
    machine = Machine()
    
    #
    
    def GLOBAL_INFO_MACHINE():
        machine.set_word(lenta_from_user.value)
        machine.set_instructions(left_row_instructions_field.value)
        a = machine.start_machine()
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
        width=800,
        height=55,
        border_radius=10,
        padding=10,
        bgcolor=main_color_2
    )

    def start_():
        cur_state = GLOBAL_INFO_MACHINE()[-1]["lenta"]
        print(cur_state)
        right_column_lenta.value = cur_state
        step_field.clean()
        page.update()
    
    button_start = ft.Container(content=
        ft.Container(content=
            ft.Container(content=
                    ft.Text("СТАРТ", size=40),
                    bgcolor=main_color_2,
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
    
    step_field = ft.ListView(
        expand = 1,
        padding= 10,
    )
  
    def step_by_step():
        left_row_step_by_step.width = 800
        left_row_step_by_step.height = 600
        left_row_step_by_step.border_radius = 10
        left_row_step_by_step.bgcolor = ft.colors.TRANSPARENT
        step_field.width = 800
        step_field.height = 600
        step_field.bgcolor = ft.colors.WHITE
        a = GLOBAL_INFO_MACHINE()
        for cur_step in a:
            step_field.controls.append(ft.Row(controls=[
                ft.Text(
                    value=cur_step["lenta"][:cur_step["position"]-1],
                    size=25,
                    height=30,
                    text_align=ft.TextAlign.CENTER,
                ),
                ft.Text(
                    value = cur_step["lenta"][cur_step["position"]-1:cur_step["position"]],
                    size=25,
                    height=30,
                    weight=ft.FontWeight.BOLD,
                    color=main_color_2,
                    text_align=ft.TextAlign.CENTER,
                ),
                ft.Text(
                    value = cur_step["lenta"][cur_step["position"]:],
                    size=25,
                    height=30,
                    text_align=ft.TextAlign.CENTER,
                ),
                ft.Text(
                    value = f"   {cur_step['from_state']}{cur_step['to_state']} {cur_step['from_letter']}{cur_step['to_letter']}  {cur_step['direction']}",
                    size=25,
                    height=30,
                    text_align=ft.TextAlign.CENTER,
                ),
            ],spacing=0, vertical_alignment=ft.CrossAxisAlignment.CENTER))
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
                border_radius=10
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
    bgcolor=main_color_3,
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
            bgcolor=ft.colors.TRANSPARENT,
            width=350,
            height=250,
            padding=10,
            border_radius=11,
            border= ft.border.all(3, main_color_2)
        ),
        ft.Container(height=20, bgcolor=ft.colors.TRANSPARENT),
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
                                ft.Text("Пример 1",size=25,text_align=ft.TextAlign.CENTER,color=ft.colors.WHITE),
                                alignment=ft.alignment.center
                            ),
                            width=130,
                            height=83,
                            bgcolor=main_color_2,
                            border_radius=10,
                            on_click=lambda e: (primer1())
                        ),
                        ft.Container(content=ft.Container(content=
                                ft.Text("Пример 2",size=25,text_align=ft.TextAlign.CENTER,color=ft.colors.WHITE),
                                alignment=ft.alignment.center
                            ),
                            width=130,
                            height=83,
                            bgcolor=main_color_2,
                            border_radius=10
                        )]
                        ),
                        ft.Row(controls=[
                            ft.Container(width=20,bgcolor=ft.colors.TRANSPARENT),
                            ft.Container(content=ft.Container(content=
                                    ft.Text("Пример 3",size=25,text_align=ft.TextAlign.CENTER,color=ft.colors.WHITE),
                                    alignment=ft.alignment.center
                                ),
                            width=130,
                            height=83,
                            bgcolor=main_color_2,
                            border_radius=10
                            ),
                            ft.Container(content=ft.Container(content=
                                    ft.Text("Пример 4",size=25,text_align=ft.TextAlign.CENTER,color=ft.colors.WHITE),
                                    alignment=ft.alignment.center
                                ),
                            width=130,
                            height=83,
                            bgcolor=main_color_2,
                            border_radius=10,
                            )
                        ])
                    ])
                )
            ]
            ),
            theme=ft.Theme(color_scheme_seed=ft.colors.INDIGO),
            theme_mode=ft.ThemeMode.DARK,
            bgcolor=ft.colors.TRANSPARENT,
            padding=10,
            width=350,
            height=250,
            border_radius=11,
            border=ft.border.all(3, main_color_2)
        )
    ])
    
    
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
        border_color=main_color_2,
        width=290,
        bgcolor=ft.colors.TRANSPARENT,
        border_radius=10,
        border_width=3,
    )
    
    left_row_rr_down = ft.Container(
        content=ft.Row(controls=[
            ft.Container(
                content= ft.Text(value="λ", size=20),
                on_click= lambda e: put_lambda(),
                width=55,
                height=55,
                bgcolor=ft.colors.TRANSPARENT,
                border_radius=10,
                alignment=ft.alignment.center,
                border= ft.border.all(3, main_color_2)
            ),
            ft.Container(
                content= ft.IconButton(
                    icon=ft.icons.DELETE_FOREVER_ROUNDED, tooltip="Очищение всех контейнеров", on_click= lambda e: clear_all_containers()),
                on_click= lambda e: clear_all_containers(),
                width=55,
                height=55,
                bgcolor=ft.colors.TRANSPARENT,
                border_radius=10,
                alignment=ft.alignment.center,
                border= ft.border.all(3, main_color_2)
            )
        ]),
        width=200,
        height=300,
        alignment=ft.alignment.top_right,
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
        bgcolor=main_color_3,
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
        bgcolor=ft.colors.TRANSPARENT,
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
        bgcolor=main_color_2,
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