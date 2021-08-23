<!DOCTYPE html>
<html lang="es">

    <head>
        <meta charset="utf-8" />
        <title>IDS</title>
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <meta content="Responsive bootstrap 4 admin template" name="description" />
        <meta content="Coderthemes" name="author" />
        <meta http-equiv="X-UA-Compatible" content="IE=edge" />
        <!-- App favicon -->
        <link rel="shortcut icon" href="assets/images/favicon.ico">

        <!-- App css -->
        <link href="assets/css/bootstrap.min.css" rel="stylesheet" type="text/css" id="bootstrap-stylesheet" />
        <link href="assets/css/icons.min.css" rel="stylesheet" type="text/css" />
        <link href="assets/css/app.min.css" rel="stylesheet" type="text/css" id="app-stylesheet" />

    </head>
    <style>
        .font-medium{

            color:#fff;
        }
    </style>

        <body   class="authentication-page" background="assets/images/fondo.jpg" >

        <div class="account-pages">
            <div class=" m-5"></div>
            <div class="container">
                <div class="row" style="    float: right; display: flex;
                align-items: center;
                justify-content: center;
                min-height: 100vh;">
                    <div class="col-12" style="
                    -webkit-box-shadow: 5px 5px 10px 5px #2cbee591;
                    box-shadow: 5px 5px 10px 5px #2cbee591;
                    -webkit-border-radius: 10px 10px 10px;
                    border-radius: 10px 10px 10px;">
                        <div class="card mt-4">
                            <div class="card-header ">
                                <img width="200" src="assets/images/logo.png" style="margin: auto; display: block;" alt="">
                               
                            </div>
                            <div class="card-body">
                                <x-jet-validation-errors class="mb-4" style="color:red" />

                                @if (session('status'))
                                <div class="mb-4 font-medium text-sm text-green-600">
                                    {{ session('status') }}
                                </div>
                            @endif

                            <form method="POST" class="p-2" action="{{ route('login') }}">
                                @csrf

                         
                                    <div class="form-group mb-3">
                                        <label for="emailaddress">Correo :</label>
                                        <input class="form-control" type="email"required="" name="email"  placeholder="EasyIds@gmail.com">
                                    </div>

                                    <div class="form-group mb-3">
                                        <label for="password">Contraseña :</label>
                                        <input class="form-control" type="password" required="" name="password"  id="password" placeholder="**********">
                                    </div>

                                    <div class="form-group mb-4">
                                        <div class="checkbox checkbox-success">
                                            <input id="remember" type="checkbox" checked="">
                                            <label for="remember">
                                                Recordarme,
                                            </label>
                                            @if (Route::has('password.request'))
                                            <a class="underline text-sm text-gray-600 hover:text-gray-900" href="{{ route('password.request') }}">
                                               Recuperar Contraseña
                                            </a>
                                        @endif
                                        </div>
                                    </div>

                                    <div class="form-group row text-center mt-4 mb-4">
                                        <div class="col-12">
                                            <button style="background: #042340;" class="btn btn-md btn-block btn-primary waves-effect waves-light" type="submit">Iniciar Sesión</button>
                                        </div>
                                    </div>

                                    <div class="form-group row mb-0">
                                        <!-- <div class="col-sm-12 text-center">
                                            <p class="text-muted mb-0">Don't have an account? <a href="pages-register.html" class="text-dark m-l-5"><b>Sign Up</b></a></p>
                                        </div> -->
                                    </div>
                                </form>

                            </div>
                            <!-- end card-body -->
                        </div>
                        <!-- end card -->

                        <!-- end row -->

                    </div>
                    <!-- end col -->
                </div>
                <!-- end row -->

            </div>
        </div>

        <!-- Vendor js -->
        <script src="assets/js/vendor.min.js"></script>

        <!-- App js -->
        <script src="assets/js/app.min.js"></script>

    </body>

</html>