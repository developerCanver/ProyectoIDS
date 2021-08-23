<x-guest-layout>
    <x-jet-authentication-card>
        <x-slot name="logo">            
        </x-slot>
        <div class="card-header ">
            <img width="200" src="assets/images/logo.png" style="margin: auto; display: block;" alt="">           
        </div>
        <br>

        <x-jet-validation-errors class="mb-4" />

        <form method="POST" action="{{ route('password.update') }}">
            @csrf

            <input type="hidden" name="token" value="{{ $request->route('token') }}">

            <div class="block">
                <x-jet-label for="email" value="Correo" />
                <x-jet-input id="email" class="block mt-1 w-full" type="email" name="email" :value="old('email', $request->email)" required autofocus />
            </div>

            <div class="mt-4">
                <x-jet-label for="password" value="Nueva Contraseña" />
                <x-jet-input id="password" class="block mt-1 w-full" type="password" name="password" required autocomplete="new-password" />
            </div>

            <div class="mt-4">
                <x-jet-label for="password_confirmation" value="Confirmar contraseña" />
                <x-jet-input id="password_confirmation" class="block mt-1 w-full" type="password" name="password_confirmation" required autocomplete="new-password" />
            </div>

            <div class="flex items-center justify-end mt-4">
                <x-jet-button>
                    {{ __('Reset Password') }}
                </x-jet-button>
            </div>
            <br>
            <p style="font-size: 12px"> <strong>Requisitos para ingresar contraseña</strong> </p>
            <p style="font-size: 12px; color: #2a620b;"> * Mayor a 8 caracteres</p>
            <p style="font-size: 12px; color: #2a620b;"> * Mínimo una mayúscula</p>
            <p style="font-size: 12px; color: #2a620b;"> * Mínimo un caracter especial</p>
         
       
        </form>
    </x-jet-authentication-card>
</x-guest-layout>
